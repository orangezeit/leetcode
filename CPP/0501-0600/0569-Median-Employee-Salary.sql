/* Write your T-SQL query statement below */
SELECT Id, Company, Salary
FROM
(SELECT Id, Company, Salary, ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary) AS row, COUNT(*) OVER (PARTITION BY Company) as num
FROM Employee) t
WHERE row BETWEEN (num + 1) / 2 AND (num + 2) / 2
;
