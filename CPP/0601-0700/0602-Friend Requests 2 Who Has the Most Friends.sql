/* Write your T-SQL query statement below */
SELECT TOP 1 ISNULL(requester_id, accepter_id) AS id, ISNULL(c1, 0) + ISNULL(c2, 0) AS num
FROM
(SELECT requester_id, COUNT(requester_id) AS c1
FROM request_accepted
GROUP BY requester_id) t1
FULL OUTER JOIN
(SELECT accepter_id, COUNT(accepter_id) AS c2
FROM request_accepted
GROUP BY accepter_id) t2
ON requester_id = accepter_id
ORDER BY num DESC;
