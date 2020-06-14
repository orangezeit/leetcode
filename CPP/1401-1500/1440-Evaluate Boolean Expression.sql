# Write your MySQL query statement below
SELECT e.*, 
CASE
    WHEN v1.value < v2.value AND e.operator = '<' THEN 'true'
    WHEN v1.value = v2.value AND e.operator = '=' THEN 'true'
    WHEN v1.value > v2.value AND e.operator = '>' THEN 'true'
    ELSE 'false'
END AS value
FROM Expressions e, Variables v1, Variables v2
WHERE e.left_operand = v1.name AND e.right_operand = v2.name;
