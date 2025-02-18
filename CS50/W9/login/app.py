from flask import Flask, request, redirect, render_template, session
from cs50 import SQL
from flask_session import Session

app = Flask(__name__)

# bat cookies va session cho trang web nay
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    return render_template("index.html", name = session.get("name"))

@app.route("/login", methods=["POST","GET"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")
