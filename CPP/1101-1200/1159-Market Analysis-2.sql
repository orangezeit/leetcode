# Write your MySQL query statement below
SELECT user_id AS seller_id, 
(CASE
    WHEN item_brand = favorite_brand THEN 'yes'
    ELSE 'no'
END) AS 2nd_item_fav_brand
FROM Users
LEFT JOIN
(SELECT seller_id, item_brand
FROM 
(SELECT a.seller_id,
    (SELECT b.item_id
    FROM Orders b
    WHERE b.seller_id = a.seller_id
    ORDER BY b.order_date
    LIMIT 1,1) AS item_id
FROM Orders a
GROUP BY a.seller_id) t
JOIN Items
ON t.item_id = Items.item_id) t2
ON user_id = seller_id;
