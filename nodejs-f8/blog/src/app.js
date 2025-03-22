const express = require('express');
const morgan = require('morgan');
const handlebars = require('express-handlebars');
const path = require('path');

const app = express()
const port = 3000

app.use(express.urlencoded({
  extended: true
}))
app.use(express.json())

app.use(morgan('combined'))

app.engine('hbs', handlebars.engine({extname:'.hbs'})); // Sửa ở đây
app.set('view engine', 'hbs');
app.set('views', path.join(__dirname, 'resource/views'));
app.use(express.static(path.join(__dirname, 'public')))

app.get('/', (req, res) => {
  res.render('home');
});

app.get('/news', (req, res) => {
  res.render('newspage');
});

app.get('/search', (req, res) => {

  res.render('search');
});

app.post('/search', (req, res) => {
  console.log(req.body)
  res.render('search');
});

app.listen(port, () => {
  console.log(`Example app listening on port http://localhost:${port}`)
})