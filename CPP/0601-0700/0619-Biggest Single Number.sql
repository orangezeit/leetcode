# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM
(SELECT num, COUNT(*) AS c
FROM my_numbers
GROUP BY num) t
WHERE c = 1;
