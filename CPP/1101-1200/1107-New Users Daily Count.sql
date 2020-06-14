# Write your MySQL query statement below
SELECT login_date, COUNT(user_id) AS user_count
FROM
(SELECT user_id, MIN(activity_date) AS login_date
FROM Traffic
WHERE activity = 'login'
GROUP BY user_id
HAVING login_date > '2019-03-31') t
GROUP BY login_date
;
