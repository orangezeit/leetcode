/* Write your T-SQL query statement below */
SELECT d.Name AS Department, e.Name AS Employee, e.Salary
FROM Employee e
JOIN
(SELECT Salary, DepartmentId, ROW_NUMBER() OVER (PARTITION BY DepartmentId ORDER BY Salary DESC) AS row
FROM 
(SELECT DISTINCT Salary, DepartmentId
FROM Employee) t) t2
ON e.Salary = t2.Salary AND e.DepartmentId = t2.DepartmentId

JOIN
Department d
ON d.Id = e.DepartmentId
WHERE row <= 3;
