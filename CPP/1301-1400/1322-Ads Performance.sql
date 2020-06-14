# Write your MySQL query statement below
SELECT ad_id,
ROUND(CASE
    WHEN total = 0 THEN 0.0
    ELSE 100 * clicks / total
END, 2) AS ctr
FROM
(SELECT ad_id,
SUM(CASE
    WHEN action = 'Clicked' THEN 1
    ELSE 0
END) AS clicks,
SUM(CASE
    WHEN action = 'Viewed' OR action = 'Clicked' THEN 1
    ELSE 0
END) AS total
FROM Ads
GROUP BY ad_id) t
ORDER BY ctr DESC, ad_id;
