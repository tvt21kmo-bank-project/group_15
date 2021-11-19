const db = require('../db');

const asiakas = {
    getById: function(id, cb) {
        return db.query('select * from asiakas where idAsiakas = ?', [id], cb);
    },
    getAll: function(cb) {
        return db.query('select * from asiakas', cb);
    },
    add: function(asiakas, cb) {
        return db.query('insert into asiakas (hetu, etunimi, sukunimi, osoite, puhelin) values(?,?,?,?,?)', 
        [asiakas.hetu, asiakas.etunimi, asiakas.sukunimi, asiakas.osoite, asiakas.puhelin], cb);
    },
    update: function(id, asiakas, cb) {
        return db.query('update asiakas set hetu=?, etunimi=?, sukunimi=?, osoite=?, puhelin=? where idAsiakas = ?',
        [asiakas.hetu, asiakas.etunimi, asiakas.sukunimi, asiakas.osoite, asiakas.puhelin, id], cb);
    },
    delete: function(id, cb) {
        return db.query('delete from asiakas where idAsiakas=?', [id], cb);
    }
};

module.exports = asiakas;