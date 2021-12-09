const db = require('../db');

const pankki = {
    selaaTapahtumia: function(edel_viim, kortti, cb) {
        return db.query('call selaa_tapahtumia(?,?)', 
        [edel_viim, kortti], cb);
    },
    haeAsiakas: function(kortti, cb) {
        return db.query(
            'SELECT etunimi, sukunimi FROM Asiakas JOIN Kortti ON Asiakas.idAsiakas = Kortti.idAsiakas WHERE kortinnumero = ?',
            [kortti], cb);
    },
    naytaSaldo: function(kortti, cb) {
        return db.query(
            'SELECT saldo FROM Tili JOIN Kortti ON Tili.idTili=Kortti.idTili WHERE kortinnumero=?', 
            [kortti], cb);
    },
    debitNosto: function(data, cb) {
        return db.query('call debit_nosto(?,?)', [data.maara, data.kortti], cb);
    }
}

module.exports = pankki;