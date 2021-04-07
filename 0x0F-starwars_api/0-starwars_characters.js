#!/usr/bin/node
const request = require('request');
const filmId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/'+process.argv[2]+'/';
request(url, async (error, response, body) => {
  if (!error) {
    const characters = JSON.parse(body).characters;
    for (const id_char in characters) {
      await new Promise((resolve, reject) => {
        request(characters[id_char], (error, response, body) => {
          if (!error) {
            console.log(JSON.parse(body).name);
            resolve();
          }
        });
      });
    }
  }
});