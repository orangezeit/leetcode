# Write your MySQL query statement below
SELECT A.visited_on, SUM(B.amount) AS amount, ROUND(AVG(B.amount), 2) AS average_amount
FROM 
 (SELECT visited_on, SUM(amount) AS amount FROM Customer GROUP BY visited_on) A,
 (SELECT visited_on, SUM(amount) AS amount FROM Customer GROUP BY visited_on) B
WHERE B.visited_on BETWEEN DATE_SUB(A.visited_on, INTERVAL 6 DAY) AND A.visited_on
GROUP BY A.visited_on
HAVING COUNT(B.amount) = 7;
