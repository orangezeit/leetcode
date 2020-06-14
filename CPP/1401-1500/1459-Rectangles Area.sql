# Write your MySQL query statement below
SELECT t1.id AS p1, t2.id AS p2, ABS(t1.x_value - t2.x_value) * ABS(t1.y_value - t2.y_value) AS area
FROM Points t1, Points t2
WHERE t1.id < t2.id
HAVING area > 0
ORDER BY area DESC, p1, p2;
