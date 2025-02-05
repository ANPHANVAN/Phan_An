WITH bacon AS (
    SELECT movies.id
    FROM movies
    JOIN stars
    ON stars.movie_id = movies.id
    JOIN people
    ON people.id = stars.person_id
    WHERE people.name =  'Kevin Bacon' AND people.birth = 1958
)

SELECT people.name
FROM stars
JOIN bacon
ON bacon.id = stars.movie_id
JOIN people
ON people.id = stars.person_id
WHERE people.name != 'Kevin Bacon' AND people.birth != 1958 ;
