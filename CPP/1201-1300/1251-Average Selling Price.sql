# Write your MySQL query statement below
SELECT u.product_id, ROUND(SUM(u.units * p.price) / SUM(u.units), 2) AS average_price
FROM UnitsSold u
JOIN Prices p
WHERE u.product_id = p.product_id AND u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
GROUP BY u.product_id;
