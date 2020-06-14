# Write your MySQL query statement below
SELECT A.gender, A.day, SUM(B.score_points) AS total
FROM Scores A, Scores B
WHERE A.gender = B.gender AND B.day <= A.day
GROUP BY A.gender, A.day
ORDER BY gender, day;
