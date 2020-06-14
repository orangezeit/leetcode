# Write your MySQL query statement below
/* Write your T-SQL query statement below */
SELECT p.spend_date, p.platform, IFNULL(s.total_amount, 0) AS total_amount, IFNULL(s.total_users, 0) AS total_users
FROM 
(
    SELECT DISTINCT(spend_date), 'desktop' platform FROM Spending
    UNION
    SELECT DISTINCT(spend_date), 'mobile' platform FROM Spending
    UNION
    SELECT DISTINCT(spend_date), 'both' platform FROM Spending
) p
LEFT JOIN
(SELECT spend_date, CASE
    WHEN sm = 0 THEN 'desktop'
    WHEN sd = 0 THEN 'mobile'
    ELSE 'both'
END AS platform,
SUM(sa) AS total_amount,
COUNT(sa) AS total_users
FROM
(SELECT spend_date, user_id, SUM(m) AS sm, SUM(d) AS sd, SUM(a) AS sa
FROM
(SELECT spend_date, user_id, CASE
    WHEN platform = 'mobile' THEN 1
    ELSE 0
END as m,
CASE
    WHEN platform = 'desktop' THEN 1
    ELSE 0
END AS d, sum(amount) AS a
FROM Spending
GROUP BY spend_date, user_id, platform) t
GROUP BY spend_date, user_id) t2
GROUP BY spend_date, sm, sd) s
ON p.spend_date = s.spend_date AND p.platform = s.platform;
