/* Write your T-SQL query statement below */
WITH record AS
(SELECT 1 AS state, success_date AS date
FROM Succeeded
WHERE success_date >= '2019-01-01' AND success_date <= '2019-12-31'
UNION ALL
SELECT 0 AS state, fail_date AS date
FROM Failed
WHERE fail_date >= '2019-01-01' AND fail_date <= '2019-12-31')

SELECT 'succeeded' AS period_state, start_date, end_date
FROM

(SELECT a.date AS start_date, row_number() over (order by a.date) AS r1
FROM (SELECT * FROM record WHERE state = 1) a
LEFT JOIN (SELECT * FROM record WHERE state = 1) b
ON a.date = DATEADD(day, 1, b.date)
WHERE b.date IS NULL) t1,

(SELECT c.date AS end_date, row_number() over (order by c.date) AS r2
FROM (SELECT * FROM record WHERE state = 1) c
LEFT JOIN (SELECT * FROM record WHERE state = 1) d
ON DATEADD(day, 1, c.date) = d.date
WHERE d.date IS NULL) t2

WHERE r1 = r2

UNION

SELECT 'failed' AS period_state, start_date, end_date
FROM

(SELECT e.date AS start_date, row_number() over (order by e.date) AS r3
FROM (SELECT * FROM record WHERE state = 0) e
LEFT JOIN (SELECT * FROM record WHERE state = 0) f
ON e.date = DATEADD(day, 1, f.date)
WHERE f.date IS NULL) t1,

(SELECT g.date AS end_date, row_number() over (order by g.date) AS r4
FROM (SELECT * FROM record WHERE state = 0) g
LEFT JOIN (SELECT * FROM record WHERE state = 0) h
ON DATEADD(day, 1, g.date) = h.date
WHERE h.date IS NULL) t4

WHERE r3 = r4
ORDER BY start_date;
