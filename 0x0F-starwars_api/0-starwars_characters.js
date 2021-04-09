#!/usr/bin/node
/* star wars api call */

const args = process.argv.slice(2);
if (args < 1) { throw new Error('Error'); }

const episode = args[0];
const url = 'https://swapi-api.hbtn.io/api/films/' + episode;
const request = require('request');

let chars = [];

request(url, (err, res, body) => {
  if (err || res.statusCode !== 200) throw new Error(err);
  chars = JSON.parse(body).characters;
  chars.forEach(function (character) {
    request(character, (err, res, body) => {
      if (err || res.statusCode !== 200) throw new Error(err);
      console.log(JSON.parse(body).name);
    });
  });
});
