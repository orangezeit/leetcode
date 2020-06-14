# Write your MySQL query statement below
SELECT business_id
FROM Events
JOIN
(SELECT event_type, AVG(occurences) as avg_occur
FROM Events
GROUP BY event_type) t
ON Events.event_type = t.event_type AND occurences > t.avg_occur
GROUP BY business_id
HAVING COUNT(business_id) > 1
;
