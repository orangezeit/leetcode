/* Write your T-SQL query statement below */
SELECT p.product_id, ISNULL(t.new_price, 10) AS price
FROM
(SELECT DISTINCT product_id FROM Products) p
LEFT JOIN
(SELECT product_id, new_price, RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS r
FROM Products
WHERE change_date <= '2019-08-16') t
ON p.product_id = t.product_id AND ISNULL(r, 1) = 1;
