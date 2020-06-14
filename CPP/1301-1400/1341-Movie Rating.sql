# Write your MySQL query statement below
(SELECT name AS results
FROM Users u
JOIN Movie_Rating m
ON u.user_id = m.user_id
GROUP BY u.user_id
ORDER BY COUNT(rating) DESC, name
LIMIT 1)
UNION
(SELECT title AS results
FROM Movies m
JOIN Movie_Rating mr
ON m.movie_id = mr.movie_id
WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY m.movie_id
ORDER BY AVG(rating) DESC, title
LIMIT 1);
