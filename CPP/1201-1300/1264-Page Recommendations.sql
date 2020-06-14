# Write your MySQL query statement below
#SELECT page_id
#FROM Likes
#WHERE user_id = 1

SELECT DISTINCT l.page_id AS recommended_page
FROM Likes l
JOIN
(SELECT
CASE
    WHEN user1_id = 1 THEN user2_id
    WHEN user2_id = 1 THEN user1_id
END AS c
FROM Friendship f) t
ON c = user_id
LEFT JOIN
(SELECT page_id
FROM Likes
WHERE user_id = 1) t2
ON l.page_id = t2.page_id
WHERE t2.page_id IS NULL;
