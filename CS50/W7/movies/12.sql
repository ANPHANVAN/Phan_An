WITH bradley_movie AS (SELECT movies.id, movies.title
FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON people.id = stars.person_id
WHERE people.name = 'Bradley Cooper'),

jennifer_movie AS (SELECT movies.id
FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON people.id = stars.person_id
WHERE people.name = 'Jennifer Lawrence')

SELECT b.title
FROM bradley_movie b
JOIN jennifer_movie j
ON b.id = j.id ;
