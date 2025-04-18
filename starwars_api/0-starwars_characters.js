#!/usr/bin/node

const request = require('request');

if (process.argv.length < 3) {
	console.error('Usage: ./0-starwars_characters.js <Movie_ID>');
	process.exit(1);
}

const movieId = process.argv[2];
const url = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(url, async (err, response, body) => {
	if (err) return console.error(err);

	const movie = JSON.parse(body);*
	const characters = movie.characters;

	for (const charUrl of characters) {
		await new Promise((resolve) => {
			request(charUrl, (err, res, body) => {
				if (!err) {
					const character = JSON.parse(body);
					console.log(character.name);
				}
				resolve();
			});
		});
	}
});

