# Write your MySQL query statement below
SELECT a.sale_date, a.sold_num - b.sold_num AS diff
FROM Sales a, Sales b
WHERE a.fruit = 'apples' AND b.fruit = 'oranges' AND a.sale_date = b.sale_date;
