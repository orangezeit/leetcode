/* Write your T-SQL query statement below */
WITH Record AS 
(SELECT player_id, event_date, ROW_NUMBER() 
          over (Partition BY player_id ORDER BY event_date) AS row
FROM Activity
)
SELECT install_dt, COUNT(*) AS installs, ROUND(AVG(c), 2) AS Day1_retention
FROM
(SELECT r1.event_date AS install_dt, r2.event_date,
CASE
    WHEN DATEDIFF(dd, r1.event_date, r2.event_date) = 1 THEN 1.0
    ELSE 0.0
END AS c
FROM Record r1
LEFT JOIN Record r2
ON r1.player_id = r2.player_id AND r1.row = r2.row - 1
where r1.row = 1) t
GROUP BY install_dt;
