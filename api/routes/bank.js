const express = require('express');
const router = express.Router();
const pankki = require('../models/bank_model');

router.get('/hae_tili/:kortti', function (req,res){
    pankki.haeTili(req.params.kortti, function(err, dbResult) {
        if(err){
            res.json(err);
        }
        else{
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
router.get('/selaa_tapahtumia/:edel_viim&:tili', function(req, res) {
    pankki.selaaTapahtumia(req.params.edel_viim, req.params.tili, 
        function(err, dbResult){
        if(err){
            res.json(err);
        }
        else {
            res.json(dbResult[0]);
        }
    })
});
router.get('/nayta_saldo/:tili', function(req,res) {
    pankki.naytaSaldo(req.params.tili, function(err, dbResult){
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult[0]);
        }
    })
});
router.post('/debit_nosto', function(req, res) {
    pankki.debitNosto(req.body, function(err, dbResult) {
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult.affectedRows);
        }
    })
})

module.exports = router;