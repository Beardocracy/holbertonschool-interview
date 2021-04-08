#!/usr/bin/node

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;

request(url, (error, response, body) => {
    if (error) {
        return;
    }
    const episode = JSON.parse(body);
    getCharacters(episode.characters, 0);
});

const getCharacters = (characters, index) => {
    if (characters.length === index) {
        return;
    }
    request(characters[index], (error, response, body) => {
        if (error) {
            return;
        }
        console.log(JSON.parse(body).name);
        getCharacters(characters, ++index);
    });
};
