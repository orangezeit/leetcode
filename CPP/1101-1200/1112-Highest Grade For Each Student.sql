/* Write your T-SQL query statement below */
SELECT student_id, course_id, grade
FROM
(SELECT student_id, course_id, grade, ROW_NUMBER() OVER (PARTITION BY student_id ORDER BY grade DESC, course_id ASC) AS row
FROM Enrollments) t1
WHERE row = 1;
