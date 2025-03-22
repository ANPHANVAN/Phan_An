class NewsController {
    
    // [GET] /news/...
    show(req, res){
        res.send("this is show /:slug of news")
    }
    
    // [GET] /news
    index(req, res) {
        res.render('newspage');
    }

}


module.exports = new NewsController