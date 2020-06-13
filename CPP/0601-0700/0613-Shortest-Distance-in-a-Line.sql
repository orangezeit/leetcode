# Write your MySQL query statement below
SELECT MIN(ABS(a.x - b.x)) AS shortest
FROM point a, point b
where a.x != b.x;
