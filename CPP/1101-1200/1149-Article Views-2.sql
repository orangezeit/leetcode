# Write your MySQL query statement below
SELECT DISTINCT viewer_id AS id
FROM
(SELECT viewer_id, COUNT(DISTINCT article_id) AS c
FROM Views
GROUP BY viewer_id, view_date
HAVING c > 1) t;
