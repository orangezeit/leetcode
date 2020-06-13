# Write your MySQL query statement below
SELECT seller_id
FROM Sales
GROUP BY seller_id
HAVING SUM(price) =
(SELECT sum(price) AS s
FROM Sales
GROUP BY seller_id
ORDER BY s DESC
LIMIT 1)
;
