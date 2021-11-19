const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', function(req, res) {
    if(req.body.kortinnumero && req.body.PIN) {
        const kortinnumero = req.body.kortinnumero;
        const PIN = req.body.PIN;
        login.checkPIN(kortinnumero, function(err, dbResult) {
            if(err){
                res.json(err);
            }
            else {
                if (dbResult.length > 0) {
                    bcrypt.compare(PIN, dbResult[0].PIN, function(err, compareResult) {
                        if(compareResult) {
                            console.log("success");
                            res.send(true);
                        }
                        else {
                            console.log("wrong PIN");
                            res.send(false);
                        }
                    })
                }
                else {
                    console.log("kortinnumero does not exist");
                    res.send(false);
                }
            }
        })
    }
    else {
        console.log("kortinnumero or PIN missing");
        res.send(false);
    }
})

module.exports = router;