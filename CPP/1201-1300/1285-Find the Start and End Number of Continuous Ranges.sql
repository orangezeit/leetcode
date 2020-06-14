/* Write your T-SQL query statement below */
SELECT start_id, end_id
FROM
(SELECT a.log_id AS start_id, row_number() over (order by a.log_id) AS r1
FROM Logs a
LEFT JOIN Logs b
ON a.log_id = b.log_id + 1
WHERE b.log_id IS NULL) t1,
(SELECT c.log_id AS end_id, row_number() over (order by c.log_id) AS r2
FROM Logs c
LEFT JOIN Logs d
ON c.log_id + 1 = d.log_id
WHERE d.log_id IS NULL) t2
WHERE r1 = r2
;
