const db = require('../db');

const login = {
    checkPIN: function(kortinnumero, cb) {
        return db.query('select PIN from kortti where kortinnumero = ?', 
        [kortinnumero], cb);
    }
};

module.exports = login;