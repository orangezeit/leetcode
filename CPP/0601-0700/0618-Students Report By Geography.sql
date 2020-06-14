/* Write your T-SQL query statement below */
WITH s1 AS
(SELECT name AS America, ROW_NUMBER() OVER (ORDER BY name) AS id
FROM student
WHERE continent = 'America'),
s2 AS
(SELECT name AS Asia, ROW_NUMBER() OVER (ORDER BY name) AS id
FROM student
WHERE continent = 'Asia'),
s3 AS
(SELECT name AS Europe, ROW_NUMBER() OVER (ORDER BY name) AS id
FROM student
WHERE continent = 'Europe')

SELECT America, Asia, Europe
FROM s1
FULL JOIN s2
ON s1.id = s2.id
FULL JOIN s3
ON s1.id = s3.id;
