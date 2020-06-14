# Write your MySQL query statement below
SELECT team_id, team_name, SUM(CASE WHEN host_team = team_id THEN host_score ELSE 0 END) + SUM(CASE WHEN guest_team = team_id THEN guest_score ELSE 0 END) AS num_points
FROM Teams
LEFT JOIN
(SELECT host_team, guest_team,
CASE
    WHEN host_goals > guest_goals THEN 3
    WHEN host_goals < guest_goals THEN 0
    ELSE 1
END AS host_score,
CASE
    WHEN host_goals > guest_goals THEN 0
    WHEN host_goals < guest_goals THEN 3
    ELSE 1
END AS guest_score
FROM Matches) t
ON host_team = team_id OR guest_team = team_id
GROUP BY team_id
ORDER BY num_points DESC, team_id;
