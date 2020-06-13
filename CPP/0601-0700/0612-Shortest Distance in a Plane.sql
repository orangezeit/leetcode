# Write your MySQL query statement below
SELECT ROUND(SQRT((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)), 2) AS shortest
FROM point_2d a, point_2d b
WHERE a.x != b.x OR a.y != b.y
ORDER BY shortest
LIMIT 1;
