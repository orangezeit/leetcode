# Write your MySQL query statement below
SELECT ROUND(COALESCE(SUM(sessions) / COUNT(user_id), 0), 2) AS average_sessions_per_user
FROM
(SELECT user_id, COUNT(DISTINCT session_id) AS sessions
FROM Activity
WHERE activity_date > '2019-06-27' AND activity_date <= '2019-07-27'
GROUP BY user_id) t
