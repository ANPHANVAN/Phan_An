from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, groupExpense
from models import add_begin_categories, add_categories, category_symbol, category_symbol_salary, add_category_expense, add_category_salary
import pandas as pd

# Configure application
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///expensive_app.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# HOME PAGE
@app.route("/")
@login_required
def index():
    # take cash balance
    cash = take_cash()

    #take data and add column day, week, month, year
    data_group_expense = db.execute("SELECT * from transactions WHERE user_id = ?", session["user_id"])
    df = pd.DataFrame(data_group_expense)
    df["day"] = pd.to_datetime(df["date"], errors='coerce').dt.to_period("D")
    df["week"] = pd.to_datetime(df["date"], errors='coerce').dt.to_period("W")
    df["month"] = pd.to_datetime(df["date"], errors='coerce').dt.to_period("M")
    df["year"] = pd.to_datetime(df["date"], errors='coerce').dt.to_period("Y")

    # divide data into 2 parts: expense and income
    df_expense = df[df["amount"] < 0].copy()
    df_income = df[df["amount"] > 0].copy()

    # number of expense
    sum_expense = df_expense["amount"].sum()

    # number of salary
    sum_salary = df_income["amount"].sum()

    # transform data expense into json
    df_expense = df_expense[["amount", "date"]]
    df_expense_group = df_expense.groupby("date")["amount"].sum().reset_index()
    df_expense_group["amount"] = - df_expense_group["amount"]
    df_expense_group = df_expense_group.to_json(orient="records")

    # transform data income into json
    df_income = df_income[["amount", "date"]]
    df_income_group = df_income.groupby("date")["amount"].sum().reset_index()
    df_income_group = df_income_group.to_json(orient="records")

    df_json_expense_group = groupExpense(df)
    # create a table expenses sort with month/week
    return render_template("home.html", cash=cash, sum_expense=sum_expense, sum_salary=sum_salary, data = df_expense_group, data_salary = df_income_group, df_json_expense_group=df_json_expense_group)
def take_cash():
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    return cash


@app.route("/transactions", methods=["GET", "POST"])
@login_required
def transaction():
    if request.method == "POST":
        if "time_range" in request.form:
            start_date = request.form.get("start_date")
            end_date = request.form.get("end_date")
            transactions = db.execute("SELECT * FROM transactions WHERE user_id = ? AND amount < 0 AND date >= ? AND date <= ? ORDER BY date DESC", session["user_id"], start_date, end_date)
            sum_transactions = sum(transaction["amount"] for transaction in transactions)
            incomes = db.execute("SELECT * FROM transactions WHERE user_id = ? AND amount > 0 AND date >= ? AND date <= ? ORDER BY date DESC", session["user_id"], start_date, end_date)
            sum_income = sum(income["amount"] for income in incomes)
            cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
            return render_template("transaction.html", transactions=transactions, sum_transactions=sum_transactions,  incomes=incomes, sum_income=sum_income, cash=cash)
        else:
            return apology("transaction")
    else:
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        transactions = db.execute("SELECT * FROM transactions WHERE user_id = ? AND amount < 0 ORDER BY date DESC", session["user_id"])
        sum_transactions = sum(transaction["amount"] for transaction in transactions)
        incomes = db.execute("SELECT * FROM transactions WHERE user_id = ? AND amount > 0 ORDER BY date DESC", session["user_id"])
        sum_income = sum(income["amount"] for income in incomes)
        return render_template("transaction.html", transactions=transactions, sum_transactions=sum_transactions,  incomes=incomes, sum_income=sum_income, cash=cash)
    
@app.route("/adds", methods=["GET", "POST"])
@login_required
def adds():
    if request.method == "POST":
        if "add_cost" in request.form:
            amount = - int(request.form.get("amount"))
            category = request.form.get("category")
            date = request.form.get("date")
            note = request.form.get("note")
            db.execute("INSERT INTO transactions (user_id, catalogies, amount, date, description) VALUES(?, ?, ?, ?, ?)", session["user_id"], category, amount, date, note)
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", amount, session["user_id"])
            return redirect("/transactions")
        
        if "add_salary" in request.form:
            amount = request.form.get("amount")
            category = request.form.get("category")
            date = request.form.get("date")
            note = request.form.get("note")
            db.execute("INSERT INTO transactions (user_id, catalogies, amount, date, description) VALUES(?, ?, ?, ?, ?)", session["user_id"], category, amount, date, note)
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", amount, session["user_id"])
            return redirect("/transactions")
    else:
        category_differences = category_symbol()
        category_differences_salary = category_symbol_salary()
        return render_template("adds.html", category_differences=category_differences, category_differences_salary=category_differences_salary)

@app.route("/settings", methods=["GET", "POST"])
@login_required
def settings():
    if request.method == "POST":
        if "add_category_expense" in request.form:
            name = request.form.get("add_category")

            # Chèn vào database
            db.execute("INSERT INTO categories (name) VALUES (?)", name)  # Thêm dấu phẩy để tạo tuple
            return redirect("/")
        
        if "add_category_salary" in request.form:
            name = request.form.get("add_category")
            db.execute("INSERT INTO categories_salary (name) VALUES(?)", name )
            return redirect("/settings")
        
        if "delete_cost" in request.form:
            name = request.form.get("input_delete_cost")
            db.execute("DELETE FROM categories WHERE name = ?", name)
            return redirect("/settings")
        
        if "delete_salary" in request.form:
            name = request.form.get("input_delete_salary")
            db.execute("DELETE FROM categories_salary WHERE name = ?", name)
            return redirect("/settings")
        return apology("error")
        
    else:
        # querry a distinct category of expenses
        categories = category_symbol()
        # querry a dinstinct category of salary
        categories_salary = category_symbol_salary()
        return render_template("settings.html", categories=categories, categories_salary=categories_salary)

@app.route("/logout")
def logout():
    """Log user out"""
    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")
    

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST" :
        # take user and password cause register
        register_username = request.form.get("username")
        register_password = request.form.get("password")

        # check password and re_password are the same
        if register_password != request.form.get("re_password"):
            return apology("Password and password(again) dont same")

        # check user name is exit, if dont exit => add users into database
        row = db.execute("SELECT * FROM users WHERE username = ?", register_username)
        if len(row) >= 1:
            return apology("users already exist")
        else:
            # add infomation
            db.execute("INSERT INTO users (username, hash, cash) VALUES(?, ?, ?)", register_username, generate_password_hash(register_password), 0)
            # take data in database
            row = db.execute("SELECT * FROM users WHERE username = ?", register_username)
            session["user_id"] = row[0]["id"]
            return redirect("/login")
    
    else:
        return render_template("register.html")
