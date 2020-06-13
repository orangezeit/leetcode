# Write your MySQL query statement below
SELECT group_id, player_id
FROM
(SELECT group_id, player_id, SUM(score) AS score
FROM
Players
JOIN
(select first_player as player, first_score as score from Matches
union all
select second_player, second_score from Matches) m
ON player_id = player
GROUP BY player_id
ORDER BY group_id, score DESC, player_id) t
GROUP BY group_id;
