// Using Node.js `require()`
const mongoose = require('mongoose');

async function connect(){
    try {
        await mongoose.connect('mongodb://127.0.0.1:27017/education_dev')
        .then(() => console.log('Connected!'));

    } catch (error) {
        console.log('Failure!');
    }
}

module.exports = { connect }

