SELECT c.name AS country
FROM Calls, Person, Country c
WHERE (caller_id = id OR callee_id = id) AND country_code = LEFT(phone_number, 3)
GROUP BY country_code
HAVING AVG(duration) > (SELECT AVG(duration) FROM Calls);
