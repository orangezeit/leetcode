# Write your MySQL query statement below
SELECT extra AS report_reason, COUNT(extra) AS report_count
FROM
(SELECT DISTINCT extra, post_id
FROM Actions
WHERE action_date = '2019-07-04' AND action = 'report'
) t
GROUP BY extra;
