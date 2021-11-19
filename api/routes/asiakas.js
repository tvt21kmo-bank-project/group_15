const express = require('express');
const router = express.Router();
const asiakas = require('../models/asiakas_model');

router.get('/:id?', function(req, res) {
    if (req.params.id) {
        asiakas.getById(req.params.id, function(err, dbResult) {
            if (err) {
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
    else {
        asiakas.getAll(function(err, dbResult) {
            if (err) {
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
})

router.post('/', function(req, res) {
    asiakas.add(req.body, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.put('/:id', function(req, res) {
    asiakas.update(req.params.id, req.body, function(err, dbResult) {
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.delete('/:id', function (req, res) {
    asiakas.delete(req.params.id, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

module.exports = router;