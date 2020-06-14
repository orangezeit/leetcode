# Write your MySQL query statement below
SELECT r1.employee_id
FROM Employees r1
left JOIN
(Select employee_id, manager_id
FROM Employees) r2
ON r1.manager_id = r2.employee_id
left JOIN
(Select employee_id, manager_id
FROM Employees) r3
ON r2.manager_id = r3.employee_id
WHERE r3.manager_id = 1 AND r1.employee_id != 1;
