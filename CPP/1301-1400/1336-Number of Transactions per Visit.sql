/* Write your T-SQL query statement below */
WITH Info AS
(SELECT v.user_id, visit_date, COUNT(amount) AS transactions_count
 FROM Visits v
 LEFT JOIN Transactions t
 ON v.user_id = t.user_id AND visit_date = transaction_date
 GROUP BY v.user_id, visit_date),
Range AS
(SELECT 0 AS num, max(transactions_count) AS m
 FROM Info
 UNION ALL
 SELECT num + 1, m
 FROM Range
 where num < m)

SELECT num AS transactions_count, ISNULL(COUNT(transactions_count), 0) as visits_count
FROM Range
LEFT JOIN Info
ON transactions_count = num
GROUP BY num
ORDER BY num;
