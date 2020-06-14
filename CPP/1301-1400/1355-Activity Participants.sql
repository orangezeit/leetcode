# Write your MySQL query statement below
SELECT activity
FROM Friends
GROUP BY activity
HAVING COUNT(activity) NOT IN
(SELECT MIN(cnt) AS cnt
FROM (SELECT activity, COUNT(activity) AS cnt
FROM Friends
GROUP BY activity) t1
UNION ALL
SELECT MAX(cnt) AS cnt
FROM (SELECT activity, COUNT(activity) AS cnt
FROM Friends
GROUP BY activity) t2);
