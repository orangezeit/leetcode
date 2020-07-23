SELECT item_category AS Category,
SUM(CASE WHEN DAYOFWEEK(order_date) = 2 THEN quantity ELSE 0 END) Monday,
SUM(CASE WHEN DAYOFWEEK(order_date) = 3 THEN quantity ELSE 0 END) Tuesday,
SUM(CASE WHEN DAYOFWEEK(order_date) = 4 THEN quantity ELSE 0 END) Wednesday,
SUM(CASE WHEN DAYOFWEEK(order_date) = 5 THEN quantity ELSE 0 END) Thursday,
SUM(CASE WHEN DAYOFWEEK(order_date) = 6 THEN quantity ELSE 0 END) Friday,
SUM(CASE WHEN DAYOFWEEK(order_date) = 7 THEN quantity ELSE 0 END) Saturday,
SUM(CASE WHEN DAYOFWEEK(order_date) = 1 THEN quantity ELSE 0 END) Sunday
FROM Items a
LEFT JOIN Orders b
ON a.item_id = b.item_id
GROUP BY item_category
ORDER BY item_category;
