# Write your MySQL query statement below
SELECT project_id
FROM Project
GROUP BY project_id
HAVING COUNT(project_id) = 
(SELECT COUNT(project_id) AS c
FROM Project
GROUP BY project_id
ORDER BY c DESC
LIMIT 1)
;
