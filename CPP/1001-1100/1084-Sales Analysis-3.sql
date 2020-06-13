# Write your MySQL query statement below
SELECT Product.product_id, product_name
FROM Product, Sales
WHERE Product.product_id = Sales.product_id
GROUP BY Sales.product_id
HAVING SUM(CASE WHEN sale_date BETWEEN "2019-01-01" AND "2019-03-31" THEN 1 ELSE 0 END) > 0
AND SUM(CASE WHEN sale_date NOT BETWEEN "2019-01-01" AND "2019-03-31" THEN 1 ELSE 0 END) = 0;
