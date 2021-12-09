var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require ('cors');
const basicAuth = require('express-basic-auth');

const asiakasRouter = require('./routes/asiakas');
const tiliRouter = require('./routes/tili');
const korttiRouter = require('./routes/kortti');
const tapahtumaRouter = require('./routes/tilitapahtuma');
const loginRouter = require('./routes/login');
const bankRouter = require('./routes/bank');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(helmet());
app.use(cors());

app.use(basicAuth( { authorizer: myAuthorizer, authorizeAsync: true, } ))
const dotenv = require('dotenv');
dotenv.config();

function myAuthorizer(username, password, cb){
    if(username===process.env.authUser && password===process.env.authPass){
        return cb(null, true);
    }
    else {
        return cb(null,false);
    }
}

app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/kortti', korttiRouter);
app.use('/tilitapahtuma', tapahtumaRouter);
app.use('/login', loginRouter);
app.use('/bank', bankRouter);

module.exports = app;
