/* Write your T-SQL query statement below */
SELECT TOP 1 person_name
FROM
(SELECT person_name, SUM(weight) OVER (ORDER BY turn) AS load, turn
FROM Queue) t
WHERE load <= 1000
ORDER BY turn DESC;
