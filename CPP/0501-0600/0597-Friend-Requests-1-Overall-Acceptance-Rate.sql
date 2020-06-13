# Write your MySQL query statement below
SELECT
CASE
    WHEN s = 0 THEN 0.00 ELSE ROUND(a / s, 2)
END AS accept_rate
FROM
(SELECT COUNT(DISTINCT sender_id, send_to_id) AS s, COUNT(DISTINCT requester_id, accepter_id) AS a
FROM friend_request, request_accepted) t
;
