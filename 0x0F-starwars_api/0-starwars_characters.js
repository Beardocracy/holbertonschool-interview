#!/usr/bin/node

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(url, (error, response, body) => {
    if (error) {
        return
    }
    const episode = JSON.parse(body);
    console.log(episode);
    console.log(response);

});
