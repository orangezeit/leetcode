/* Write your T-SQL query statement below */
WITH Record AS
(SELECT s.employee_id, department_id, amount, cast(datepart(YYYY,pay_date) as varchar) + '-' + FORMAT(pay_date, 'MM') AS ym
FROM salary s
JOIN
employee e
ON s.employee_id = e.employee_id)

SELECT DISTINCT pay_month, department_id,
CASE
    WHEN department_salary > company_salary THEN 'higher'
    WHEN department_salary < company_salary THEN 'lower'
    ELSE 'same'
END AS comparison
FROM
(SELECT r.ym AS pay_month, department_id, AVG(amount) OVER (PARTITION BY department_id, r.ym) AS department_salary, company_salary
FROM Record r
JOIN 
(SELECT ym, AVG(amount) AS company_salary
FROM Record
GROUP BY ym) t
ON t.ym = r.ym) t2;
