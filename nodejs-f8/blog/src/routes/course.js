const express = require('express');
const router = express.Router();

// link to NewsController file
const courseController = require('../app/controllers/CourseController');

//  route /course/create
router.use('/create', courseController.create);

// route /course/store
router.use('/store', courseController.store);

// route /course/...
router.use('/:slug', courseController.slug);

// route /course
router.use('/', courseController.index);

module.exports = router;
