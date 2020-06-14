# Write your MySQL query statement below
SELECT query_name, ROUND(AVG(rating * 100 / position) , 0) / 100 AS quality,
       ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) * 100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;
