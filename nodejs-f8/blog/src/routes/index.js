function route(app){
    const newsRouter = require('./news')
    const siteRouter = require('./site')

    // handling route /news and /news/...
    app.use('/news', newsRouter)

    // handling route / , /search
    app.use('/', siteRouter)
}

module.exports = route;