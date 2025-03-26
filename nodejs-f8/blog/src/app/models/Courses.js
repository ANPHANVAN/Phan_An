const mongoose = require('mongoose');
slug = require('mongoose-slug-generator')
const Schema = mongoose.Schema;
const mongooseDelete = require('mongoose-delete');

const Course = new Schema({
  name: {type:String, maxLength: 255},
  description: {type:String,  maxLength: 255},
  image: {type:String, maxLength: 255},
  slug: { type: String, slug: "name"},
  register: {type: String, default: 'Đăng ký học'},
  createAt: {type: Date, default: Date.now},
  updateAt: {type: Date, default: Date.now},
});

//  Add plugin 
mongoose.plugin(slug)
Course.plugin(mongooseDelete, {
  deletedAt : true,
  overrideMethods: 'all'
})

module.exports = mongoose.model('Course', Course);

