/* Write your T-SQL query statement below */
SELECT SUM(TIV_2016) AS TIV_2016
FROM
(SELECT i.TIV_2015, TIV_2016, i.LAT, i.LON, c1, c2
FROM insurance i
JOIN
(SELECT COUNT(*) AS c1, LAT, LON
FROM insurance
GROUP BY LAT, LON) t1
ON i.LAT = t1.LAT AND i.LON = t1.LON
JOIN
(SELECT COUNT(*) AS c2, TIV_2015
FROM insurance
GROUP BY TIV_2015) t2
ON i.TIV_2015 = t2.TIV_2015) t
WHERE c1 = 1 AND c2 > 1;
