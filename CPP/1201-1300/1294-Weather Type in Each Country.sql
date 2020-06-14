# Write your MySQL query statement below
SELECT country_name,
CASE
    WHEN tmp <= 15 THEN "Cold"
    WHEN tmp >= 25 THEN "Hot"
    ELSE "Warm"
END AS weather_type
FROM Countries c
JOIN
(SELECT country_id, AVG(weather_state) AS tmp
FROM Weather
WHERE MONTH(day) = 11 AND YEAR(day) = 2019
GROUP BY country_id) w
ON c.country_id = w.country_id;
