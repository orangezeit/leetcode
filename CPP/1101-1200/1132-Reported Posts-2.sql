# Write your MySQL query statement below
SELECT ROUND(AVG(c),2) AS average_daily_percent
FROM
(SELECT COUNT(DISTINCT r.post_id) / COUNT(DISTINCT t.post_id) * 100 AS c
FROM
(SELECT action_date, post_id
FROM Actions
WHERE extra = 'spam') t
LEFT JOIN Removals r
ON r.post_id = t.post_id
GROUP BY action_date) t2
;
