from flask import Flask, request, render_template
from cs50 import SQL

app = Flask(__name__)

SPORTS = [
    "football",
    "soccer",
    "voleyball",
]

db = SQL("sqlite:///sports.db")

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("failure.html", message="missing name")

    sport=request.form.get("sport")
    if not sport:
        return render_template("failure.html", message="missing sport")
    if sport not in SPORTS:
        return render_template("failure.html", message="unvalid sport")

    db.execute("INSERT INTO registaints (name, sport) VALUES(?, ?)", name, sport)
    return render_template("success.html")

@app.route("/registaints")
def registaints():
    registaints = db.execute("SELECT name, sport FROM registaints")
    return render_template("registaints.html", registaints = registaints)
