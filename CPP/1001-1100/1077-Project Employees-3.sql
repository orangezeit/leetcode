# Write your MySQL query statement below
SELECT t.project_id, t.employee_id
FROM
(SELECT project_id, p.employee_id, experience_years
FROM Project p
JOIN Employee e
ON p.employee_id = e.employee_id) t
JOIN
(SELECT project_id, MAX(experience_years) AS max_years
FROM Project p
JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY project_id) t2
ON t.project_id = t2.project_id AND t.experience_years = max_years;
