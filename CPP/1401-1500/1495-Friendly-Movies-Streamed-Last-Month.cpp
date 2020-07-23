SELECT DISTINCT title
FROM Content c
JOIN TVProgram t
ON c.content_id = t.content_id
WHERE YEAR(program_date) = 2020 AND MONTH(program_date) = 6 AND Kids_content = "Y" AND content_type = "Movies";
