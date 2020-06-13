# Write your MySQL query statement below
SELECT b.book_id, name
FROM Books b
LEFT JOIN
(SELECT book_id, SUM(
    CASE
        WHEN dispatch_date <= '2019-06-23' AND dispatch_date >= '2018-06-23' then quantity
        ELSE 0
    END) AS sold
FROM Orders
GROUP BY book_id) t
ON b.book_id = t.book_id
WHERE available_from < '2019-05-23' AND IFNULL(sold, 0) < 10;
