const Course = require('../../models/Courses')
const { multipleMongooseToObject, mongooseToObject } = require('../../../tool/toobject')

class MeController {

  // [GET] /me/my-course
  async indexCourse(req, res, next) {
    try {
      let courses = await Course.findActive();
      courses = multipleMongooseToObject(courses);
      let numberBin = await Course.countDocuments({deleted: true})
      console.log(numberBin)
      res.render('me/me-my-course', {courses, numberBin})
    } catch (err) {
      res.status(400).json({ error: 'error!' });
    }
  }

  // [GET] /me/:id/edit
  async changeCourse(req, res, next) {
    try {
      let id = req.params.id;
      let courses = await Course.find({})
      courses = multipleMongooseToObject(courses)
      let course = courses.find(course => course._id == id)
      res.render('./me/change-course', {course})
    }
    catch (err) {
      res.status(400).json({ error: 'error!' });
    }

  }

  // [POST][PUT] /me/:id
  async change(req, res, next) {
    try {
      let id = req.params.id;
      let updateCourse = req.body
      Course.updateOne({_id: id}, updateCourse)
        .then(() => res.redirect('/me/my-course'))
        .catch(next)
    }
    catch (err) {
      res.status(400).json({ error: 'error!' });
    }

  }

  // [DELETE] /me/:id
  async delete(req, res, next) {
    try {
      let id = req.params.id;
      Course.delete({_id: id})
        .then(() => res.redirect('/me/my-course'))
        .catch(next)
    } catch (err) {
      res.status(400).json({ error: 'error!' });
    }
  }

  // [PATCH] /me/:id/restore
  async restore(req, res, next) {
    try {
      let id = req.params.id;
      // res.send(id)
      Course.restore({_id: id})
        .then(() => res.redirect('/me/bin'))
        .catch(next)
    }
    catch (err) {
      res.status(400).json({ error: 'error!' });
    }
  }

    // [GET] /me/bin
    async bin(req, res, next) {
      try {
        let courseDeletes = await Course.findDeleted()
        courseDeletes = multipleMongooseToObject(courseDeletes)
        res.render('me/bin', {courseDeletes})
      }
      catch (err) {
        res.status(400).json({ error: 'error!' });
      }
    }

      // [DELETE] /me/:id/permanent
  async destroy(req, res, next) {
    try {
      let id = req.params.id;
      Course.findOneAndDelete({ _id: id })
        .then(() => res.redirect('/me/bin'))
        .catch(next)
    } catch (err) {
      res.status(400).json({ error: 'error!' });
    }
  }

  async deleteAll(req, res, next) {
    try {
      let courseIds = req.body.courseIds
      Course.deleteMany({ _id: { $in: courseIds } })
        .then(() => res.redirect('/me/my-course'))
        .catch(next)

    } catch (err) {
      res.status(400).json({ error: 'error!' });
    }
  }
}
module.exports = new MeController();