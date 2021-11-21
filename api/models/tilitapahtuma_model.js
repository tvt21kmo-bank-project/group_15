const db = require('../db');

const tapahtuma = {
    getById: function(id, cb){
        return db.query('SELECT * FROM tilitapahtuma WHERE idTapahtuma = ?', [id], cb);
    },
    getAll: function(cb){
        return db.query('SELECT * FROM tilitapahtuma', cb);
    },
    add: function(tapahtuma, cb){
        return db.query('INSERT INTO tilitapahtuma (kortinnumero, aika, tapahtuma, summa, idTili) VALUES (?, now(), ?,?,?)',
        [tapahtuma.kortinnumero, tapahtuma.tapahtuma, tapahtuma.summa, tapahtuma.idTili], cb);
    },
    update: function(id, tapahtuma, cb){
        return db.query('UPDATE tilitapahtuma SET kortinnumero=?, aika=?, tapahtuma=?, summa=?, idTili=? WHERE idTapahtuma=?',
        [tapahtuma.kortinnumero, tapahtuma.aika, tapahtuma.tapahtuma, tapahtuma.summa, tapahtuma.idTili, id], cb);
    },
    delete: function(id, cb){
        return db.query('DELETE FROM tilitapahtuma WHERE idTapahtuma=?', [id], cb);
    }
}

module.exports = tapahtuma;