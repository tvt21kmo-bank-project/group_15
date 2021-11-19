const db = require('../db');

const tili = {
    getById: function(id, cb) {
        return db.query('select * from tili where idTili = ?', [id], cb);
    },
    getAll: function(cb) {
        return db.query('select * from tili', cb);
    },
    add: function(tili, cb) {
        return db.query('insert into tili (tilinumero, saldo) values (?,?)', [tili.tilinumero, tili.saldo], cb);
    },
    update: function(id, tili, cb) {
        return db.query('update tili set tilinumero=?, saldo=? where idTili=?', [tili.tilinumero, tili.saldo, id], cb);
    },
    delete: function(id, cb) {
        return db.query('delete from tili where idTili=?', [id], cb);
    }
}

module.exports = tili;