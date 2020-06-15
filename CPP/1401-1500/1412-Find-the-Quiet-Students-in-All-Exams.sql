# Write your MySQL query statement below
SELECT DISTINCT e2.student_id, student_name
FROM Student s,
(SELECT DISTINCT student_id
FROM Exam e,
(SELECT exam_id, MAX(score) AS max_score, MIN(score) AS min_score
FROM Exam
GROUP BY exam_id) t
WHERE e.exam_id = t.exam_id AND (e.score = t.max_score OR e.score = t.min_score)) t2
RIGHT JOIN Exam e2
ON t2.student_id = e2.student_id
WHERE t2.student_id IS NULL AND s.student_id = e2.student_id
ORDER BY e2.student_id;
