# Write your MySQL query statement below
SELECT user_id AS buyer_id, join_date, COALESCE(t.c, 0) AS orders_in_2019
FROM Users
LEFT JOIN
(SELECT buyer_id, COUNT(buyer_id) AS c
FROM Orders
WHERE order_date >= '2019-01-01' AND order_date <= '2019-12-31'
GROUP BY buyer_id) t
ON user_id = buyer_id;
