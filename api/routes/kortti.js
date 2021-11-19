const express = require('express');
const router = express.Router();
const kortti = require('../models/kortti_model');

router.get('/:id?', function(req, res) {
    if (req.params.id) {
        kortti.getById(req.params.id, function(err, dbResult){
            if (err) {
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
    else {
        kortti.getAll(function(err, dbResult) {
            if (err) {
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
})

router.post('/', function(req,res) {
    kortti.add(req.body, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.put('/:id', function(req, res) {
    kortti.update(req.params.id, req.body, function(err, dbResult){
        if(err){
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.delete('/:id', function(req, res) {
    kortti.delete(req.params.id, function(err, dbResult) {
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

module.exports = router;