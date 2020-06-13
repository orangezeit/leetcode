/* Write your T-SQL query statement below */
SELECT player_id, event_date, SUM(games_played) over (PARTITION BY player_id ORDER BY event_date) AS games_played_so_far
FROM Activity;
