# Write your MySQL query statement below
SELECT a.product_id, a.year AS first_year, quantity, price
FROM Sales a
JOIN (SELECT product_id, MIN(year) AS year
FROM Sales
GROUP BY product_id) b
ON a.product_id = b.product_id AND a.year = b.year;
