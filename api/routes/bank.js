const express = require('express');
const router = express.Router();
const pankki = require('../models/bank_model');

router.get('/selaa_tapahtumia/:edel_viim&:kortti', function(req, res) {
    pankki.selaaTapahtumia(req.params.edel_viim, req.params.kortti, 
        function(err, dbResult){
        if(err){
            res.json(err);
        }
        else {
            res.json(dbResult[0]);
        }
    })
});
router.get('/hae_asiakas/:kortti', function(req, res){
    pankki.haeAsiakas(req.params.kortti, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult[0]);
        }
    })
});
router.get('/nayta_saldo/:kortti', function(req,res) {
    pankki.naytaSaldo(req.params.kortti, function(err, dbResult){
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult[0]);
        }
    })
});

module.exports = router;