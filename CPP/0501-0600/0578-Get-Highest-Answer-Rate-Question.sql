# Write your MySQL query statement below
SELECT question_id AS survey_log
FROM
(SELECT question_id, SUM(CASE
    WHEN action = 'answer' THEN 1.0
    ELSE 0.0
END) / (COUNT(*) - 1.0) AS rate
FROM survey_log
GROUP BY question_id
ORDER BY rate DESC
LIMIT 1) t;
