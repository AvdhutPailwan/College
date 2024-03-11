'use strict';
const {
  Model
} = require('sequelize');
module.exports = (sequelize, DataTypes) => {
  class User extends Model {
    /**
     * Helper method for defining associations.
     * This method is not a part of Sequelize lifecycle.
     * The `models/index` file will call this method automatically.
     */
    static associate(models) {
      // define association here
    }

    static findAllUsers(){
      return this.findAll()
    }

    static newUserRegister({name, email, password, dob, mobileNumber}){
      return this.create({
        name,
        email,
        password,
        dob,
        mobileNumber
      })
    }
  }
  User.init({
    name: DataTypes.STRING,
    email: DataTypes.STRING,
    password: DataTypes.STRING,
    dob: DataTypes.DATEONLY,
    mobileNumber: DataTypes.INTEGER
  }, {
    sequelize,
    modelName: 'User',
  });
  return User;
};