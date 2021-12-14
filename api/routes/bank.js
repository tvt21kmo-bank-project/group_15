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
router.get('/hae_omistaja/:tili', function(req, res){
    pankki.haeOmistaja(req.params.tili, function(err, dbResult){
        if(err){
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
});
router.get('/hae_5_tapahtumaa/:tili', function(req,res) {
    pankki.hae5tapahtumaa(req.params.tili, function(err, dbResult){
        if (err) {
            res.json(err);
        }
        else {
            res.json(dbResult);
        }
    })
});
router.put('/lukitse_kortti', function(req, res) {
    pankki.lukitseKortti(req.body, function(err, dbResult){
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult.affectedRows);
        }
    })
});
router.get('/tarkista_lukitus/:kortti', function(req, res) {
    pankki.tarkistaLukitus(req.params.kortti, function(err, dbResult){
        if(err) {
            res.json(err);
        }
        else {
            res.json(dbResult[0]);
        }
    })
});

module.exports = router;