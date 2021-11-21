const db = require('../db');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const kortti = {
    getById: function(id, cb) {
        return db.query('select * from kortti where idKortti = ?', [id], cb);
    },
    getAll: function(cb) {
        return db.query('select * from kortti', cb);
    },
    add: function(kortti, cb) {
        bcrypt.hash(kortti.PIN, saltRounds, function(err, hash) {
        return db.query('insert into kortti (kortinnumero, PIN, idAsiakas, idTili) values (?,?,?,?)', 
        [kortti.kortinnumero, hash, kortti.idAsiakas, kortti.idTili], cb);
        })
    },
    update: function(id, kortti, cb) {
        bcrypt.hash(kortti.PIN, saltRounds, function(err, hash) {
        return db.query('update kortti set kortinnumero=?, PIN=?, idAsiakas=?, idTili=? where idKortti=?', 
        [kortti.kortinnumero, hash, kortti.idAsiakas, kortti.idTili, id], cb);
        })
    },
    delete: function (id, cb){
        return db.query('delete from kortti where idKortti=?', [id], cb);
    }
}

module.exports = kortti;