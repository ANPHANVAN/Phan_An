const Course = require('../models/Courses')
const { multipleMongooseToObject } = require('../../tool/toobject')
class SiteController {
  // [GET] Home /
  async home(req, res) {
    try {
      let courses = await Course.find({});
      console.log(courses) 

      courses = multipleMongooseToObject(courses)
      console.log(courses) 
      res.render('home',{
        courses: courses
      })
    }
    catch (err) {
        res.status(400).json({ error: 'error!' });
    }
      // res.render('home');
  }
  // [GET] /search
  search(req, res) {
    res.render('search');
  }
}

module.exports = new SiteController();
