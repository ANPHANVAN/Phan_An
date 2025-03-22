const express = require('express');
const router = express.Router();

// link to NewsController file
const newsController = require('../app/controllers/NewsController');

// route /news/...
router.use('/:slug', newsController.show);

// route /news
router.use('/', newsController.index);

module.exports = router;
