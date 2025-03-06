from flask import flask, render_template, request, redirect

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/buy")
def buy():
    return render_template("buy.html")
    
