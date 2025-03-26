function route(app) {
  const newsRouter = require('./news');
  const siteRouter = require('./site');
  const courseRouter = require('./course');
  const meRouter = require('./me');


  // handling route /news and /news/...
  app.use('/news', newsRouter);

  // handling route /course and /course/...
  app.use('/course', courseRouter);
  
  app.use('/me', meRouter);

  // handling route / , /search
  app.use('/', siteRouter);
}

module.exports = route;
