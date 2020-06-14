# Write your MySQL query statement below
SELECT t1.sub_id AS post_id, IFNULL(t2.c, 0) AS number_of_comments
FROM
(SELECT DISTINCT sub_id
FROM Submissions
WHERE parent_id IS NULL) t1
LEFT JOIN
(SELECT parent_id, COUNT(DISTINCT sub_id) AS c
FROM Submissions
WHERE parent_id IS NOT NULL
GROUP BY parent_id) t2
ON t1.sub_id = t2.parent_id
ORDER BY post_id
;
