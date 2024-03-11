const express = require('express')
const app = express()
const {User} = require('./models')
const path = require('path')
const bodyParser = require('body-parser')

app.use(bodyParser.json())
app.set('views', path.join(__dirname, 'views'))
app.use(express.static(path.join(__dirname, 'public')))
app.set('view engine', 'ejs')
app.use(bodyParser.urlencoded({extended: true}))

app.get('/', async (req, res) => {
    // const insert = await User.create({
    //         name: 'Avdhut Pailwan',
    //         email: 'ap@gmail.com',
    //         password: '123',
    //         dob: new Date().toISOString().split('T')[0]
    //     })
    // const d = await User.destroy({
    //     where: {

    //     }
    // })
    // const response = await User.findAllUsers()
    return res.render('form')
})

app.post('/register', async (req, res) => {
    console.log(req.body)
    try {
        const newUser = await User.newUserRegister({
            name: req.body.name,
            email: req.body.email,
            password: req.body.password,
            dob: req.body.dob,
            mobileNumber: req.body.mobileNumber
        })

        return res.redirect('/')
    } catch (error) {
        console.error(error, "Error at '/register' route")
    }
})

app.get('/users', async (req, res) => {
    try {
        const allUsers = await User.findAllUsers()
        console.log(allUsers[0].dataValues)
        return res.render('users', {
            allUsers
        })
    } catch (error) {
        
    }
})

module.exports = app
