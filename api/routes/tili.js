const express = require('express');
const router = express.Router();
const tili = require('../models/tili_model');

router.get('/:id?', function(req, res) {
    if (req.params.id) {
        tili.getById(req.params.id, function(err, dbResult){
            if (err){
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
    else {
        tili.getAll(function(err, dbResult) {
            if (err){
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
})

router.post('/', function(req, res){
    tili.add(req.body, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.put('/:id', function(req, res) {
    tili.update(req.params.id, req.body, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.delete('/:id', function(req, res){
    tili.delete(req.params.id, function(err, dbResult){
        if (err){
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

module.exports = router;