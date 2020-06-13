/* Write your T-SQL query statement below */
SELECT ROUND(AVG(c), 2) AS immediate_percentage
FROM
(SELECT customer_id, 
CASE
    WHEN order_date = customer_pref_delivery_date THEN 100.0
    ELSE 0.0
END AS c
FROM
(SELECT customer_id, order_date, customer_pref_delivery_date, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) as row
FROM Delivery) t
WHERE row = 1) t1;
