# Write your MySQL query statement below
SELECT c.customer_id, customer_name
FROM Orders o, Customers c
WHERE o.customer_id = c.customer_id
GROUP BY c.customer_id
HAVING SUM(CASE
    WHEN product_name = 'A' OR product_name = 'B' THEN 1
    WHEN product_name = 'C' THEN -1
    ELSE 0
END) = 2;
