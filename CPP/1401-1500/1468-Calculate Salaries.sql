# Write your MySQL query statement below
SELECT s.company_id, s.employee_id, s.employee_name, ROUND(s.salary * rate, 0) AS salary
FROM Salaries s, 
(SELECT company_id, CASE
    WHEN MAX(salary) < 1000 THEN 1.0
    WHEN MAX(salary) > 10000 THEN 0.51
    ELSE 0.76
END AS rate
FROM Salaries
GROUP BY company_id) t
WHERE s.company_id = t.company_id;
