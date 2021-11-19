const express = require('express');
const router = express.Router();
const tapahtuma = require('../models/tilitapahtuma_model');

router.get('/:id?', function(req, res) {
    if (req.params.id) {
        tapahtuma.getById(req.params.id, function(err, dbResult){
            if (err) {
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
    else {
        tapahtuma.getAll(function(err, dbResult){
            if(err) {
                res.json(err);
            }
            else {
                res.json(dbResult);
            }
        })
    }
})

router.post('/', function(req, res) {
    tapahtuma.add(req.body, function(err, dbResult){
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.put('/:id', function(req, res) {
    tapahtuma.update(req.params.id, req.body, function(err, dbResult){
        if(err){
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

router.delete('/:id', function(req, res){
    tapahtuma.delete(req.params.id, function(err, dbResult){
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
})

module.exports = router;