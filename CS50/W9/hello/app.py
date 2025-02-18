from flask import Flask, render_template, request

app = Flask("name")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "World!")
    return render_template("greet.html", name=name)