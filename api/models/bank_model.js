const db = require('../db');

const pankki = {
    haeTili: function(kortti, cb) {
        return db.query('SELECT tilinumero FROM Tili JOIN Kortti ON Tili.idTili=Kortti.idTili WHERE kortinnumero=?',
        [kortti], cb);
    },
    haeAsiakas: function(kortti, cb) {
        return db.query(
            'SELECT etunimi, sukunimi FROM Asiakas JOIN Kortti ON Asiakas.idAsiakas = Kortti.idAsiakas WHERE kortinnumero = ?',
            [kortti], cb);
    },
    selaaTapahtumia: function(edel_viim, tili, cb) {
        return db.query('call selaa_tapahtumia(?,?)', 
        [edel_viim, tili], cb);
    },
    naytaSaldo: function(tili, cb) {
        return db.query(
            'SELECT saldo FROM Tili WHERE tilinumero=?', 
            [tili], cb);
    },
    debitNosto: function(data, cb) {
        return db.query('call debit_nosto(?,?,?)', [data.maara, data.kortti, data.tili], cb);
    }
};

module.exports = pankki;