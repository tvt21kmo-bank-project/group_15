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
    },
    hae5tapahtumaa: function(tili, cb) {
        return db.query('SELECT aika, kortinnumero, summa, tapahtuma FROM Tilitapahtuma tt JOIN Tili t ON t.idTili = tt.idTili WHERE tilinumero =? ORDER BY aika DESC LIMIT 5',
        [tili], cb);
    },
    lukitseKortti: function (data, cb) {
        return db.query('UPDATE Kortti SET kortinnumero=? WHERE kortinnumero = ?',
        [data.lukittuKortti, data.kortinnumero], cb);
    }
};

module.exports = pankki;