/* Write your T-SQL query statement below */
SELECT Name
FROM
(SELECT TOP 1 Name, v
FROM Candidate c
FULL OUTER JOIN
(SELECT DISTINCT CandidateId, COUNT(*) AS v
FROM Vote
GROUP BY CandidateId) t
ON c.id = t.CandidateId
ORDER BY v DESC) t2
WHERE Name IS NOT NULL AND v IS NOT NULL;
