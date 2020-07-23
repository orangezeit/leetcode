SELECT c.customer_id, name
FROM Customers c
JOIN
(SELECT customer_id, SUM(quantity * price) AS total
FROM Product p
JOIN Orders o
ON p.product_id = o.product_id
WHERE YEAR(order_date) = 2020 AND (MONTH(order_date) = 6 OR MONTH(order_date) = 7)
GROUP BY customer_id, MONTH(order_date)
HAVING total >= 100) t
ON c.customer_id = t.customer_id
GROUP BY c.customer_id
HAVING COUNT(c.customer_id) > 1;
