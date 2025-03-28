const express = require('express');
const router = express.Router();

const meController = require('../app/controllers/Me/MyCourseController');

// route /me/my-course
router.use('/my-course', meController.indexCourse);
router.get('/bin', meController.bin)
router.use('/:id/edit', meController.changeCourse)
router.delete('/:id', meController.delete)
router.delete('/:id/permanent', meController.destroy)
router.patch('/:id/restore', meController.restore)
router.use('/:id', meController.change)

module.exports = router;
