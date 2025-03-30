//  import from library
const express = require('express');
const morgan = require('morgan');

// import from my file
const route = require('./routes');

app = express();
const port = 3000;

app.use(morgan('combined'));
app.use(express.static('public'));

app.set('view engine' , 'pug');
app.set('views', 'src/views');
route(app);

app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});