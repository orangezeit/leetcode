# Write your MySQL query statement below
SELECT Name
FROM Employee
JOIN
(SELECT ManagerId, COUNT(ManagerId) AS c
FROM Employee
GROUP BY ManagerId) t
ON t.c >= 5 AND Employee.Id = t.ManagerId;
