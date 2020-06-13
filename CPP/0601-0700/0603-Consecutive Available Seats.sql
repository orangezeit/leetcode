/* Write your T-SQL query statement below */

SELECT id AS seat_id
FROM
(SELECT id, 
CASE
    WHEN curr = 1 AND next = 1 THEN 1
    WHEN curr = 1 AND c.free = 1 THEN 1
    ELSE 0
END AS signal
FROM
(SELECT a.seat_id AS id, a.free AS curr, b.free AS next
FROM cinema a
LEFT JOIN cinema b
ON a.seat_id = b.seat_id - 1) t
LEFT JOIN cinema c
ON id = c.seat_id + 1) t1
WHERE signal = 1;
