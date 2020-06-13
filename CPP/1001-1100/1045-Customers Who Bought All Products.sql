# Write your MySQL query statement below
SELECT customer_id
FROM Customer, Product
WHERE Customer.product_key = Product.product_key
GROUP BY customer_id
having COUNT(DISTINCT Product.product_key) = (SELECT COUNT(*) FROM Product);
