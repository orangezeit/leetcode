/* Write your T-SQL query statement below */
SELECT dept_name, ISNULL(c, 0) AS student_number
FROM department d
LEFT JOIN
(SELECT dept_id, COUNT(*) AS c
FROM student
GROUP BY dept_id) t
ON t.dept_id = d.dept_id
ORDER BY c DESC, dept_name ASC;
