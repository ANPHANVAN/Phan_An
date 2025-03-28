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
  deleted: {type: Boolean, default: false},
  deletedAt: {type: Date, default: null}
});

//  Add plugin 
mongoose.plugin(slug)
Course.plugin(mongooseDelete, {
  deletedAt: true,
  overrideMethods: ['findOne', 'findById', 'count', 'countWithDeleted',  'findOneAndUpdate', 'findByIdAndUpdate', 'findOneAndDelete', 'findByIdAndDelete']
});
Course.statics.findDeleted = function() {
  console.log('Running findDeleted with query:', { deleted: true });
  return this.find({ deleted: true });
};
Course.statics.findActive = function() {
  return this.find({
    $or: [
      { deleted: false },           // Các document có deleted: false
      { deleted: { $exists: false } } // Các document không có trường deleted
    ]
  });
};
module.exports = mongoose.model('Course', Course);

