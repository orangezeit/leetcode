# Write your MySQL query statement below
SELECT buyer_id
FROM Sales
GROUP BY buyer_id
HAVING SUM(CASE WHEN product_id = (SELECT product_id FROM Product WHERE product_name = "S8") THEN 1 ELSE 0 END) > 0
AND SUM(CASE WHEN product_id = (SELECT product_id FROM Product WHERE product_name = "iPhone") THEN 1 ELSE 0 END) = 0;
