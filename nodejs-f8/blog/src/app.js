const express = require("express");
const morgan = require("morgan");
const handlebars = require("express-handlebars");
const path = require("path");
const db = require('./config/db')
var methodOverride = require('method-override')
const route = require(path.join(__dirname, "routes"));

const app = express();
const port = 3000;

db.connect()

app.use(methodOverride('_method'))
app.use(methodOverride('X-HTTP-Method-Override'));

app.use(express.static(path.join(__dirname, "public")));
// config connect DB

app.use(
  express.urlencoded({
    extended: true,
  })
);
app.use(express.json());
app.use(morgan("combined"));


app.engine("hbs", handlebars.engine({ extname: ".hbs",
  helpers: { sum: (a,b) => a+b}
}));
app.set("view engine", "hbs");
app.set("views", path.join(__dirname, "resource/views"));


route(app);


app.listen(port, () => {
  console.log(`App listening on port http://localhost:${port}`);
});
