const Course = require('../models/Courses')
const { multipleMongooseToObject } = require('../../tool/toobject')

class CourseController {
  async index(req, res) {
    try {
      let courses = await Course.find({});
      courses = multipleMongooseToObject(courses)
      res.render('course',{courses: courses})
    } 
    catch (err) {
        res.status(400).json({ error: 'error!' });
    }
  }

  async slug(req, res) {
    try {
        const slugName = req.params.slug;
        let courses = await Course.find({});
        courses = multipleMongooseToObject(courses);
        let course = courses.find((course) => course.slug == slugName);
        res.render('course-detail', course);
    } catch (error) {
        console.error("Error:", error);
        res.status(500).send("Something went wrong");
    }
  }
  async create(req, res) {
    res.render('course-create')
  }
  async store(req, res) {
    const courseCreate = new Course(req.body);
    await courseCreate.save()
      .then(() => res.redirect('/course'))
      .catch(error => res.send('your course dont create'))
  }
}

module.exports = new CourseController();