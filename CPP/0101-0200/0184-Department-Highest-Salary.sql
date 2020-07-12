/* Write your T-SQL query statement below */
SELECT d.Name AS Department, e.Name AS Employee, Salary
FROM Employee e
JOIN
(SELECT MAX(Salary) AS target, DepartMentId
FROM Employee
GROUP BY DepartmentId) t
ON Salary = target AND e.DepartmentId = t.DepartmentId
JOIN Department d
ON e.DepartMentId = d.Id;
