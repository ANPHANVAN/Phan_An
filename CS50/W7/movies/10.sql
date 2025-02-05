SELECT DISTINCT people.name
FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON people.id = stars.person_id
JOIN ratings
ON ratings.movie_id = movies.id
WHERE ratings.rating >= 9.0;

-- dữ liệu bị sai, không có cột direct từ phim
