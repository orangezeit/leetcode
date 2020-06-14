# Write your MySQL query statement below
SELECT invoice_id, customer_name, price,
        COUNT(contact_email) AS contacts_cnt, 
        IFNULL(SUM(contact_email in (Select distinct email from Customers)), 0) AS trusted_contacts_cnt

FROM
(SELECT invoice_id, customer_name, price, customer_id
FROM Invoices inv, Customers
WHERE inv.user_id = customer_id
GROUP BY invoice_id) t
LEFT JOIN Contacts co
ON customer_id = co.user_id
GROUP BY invoice_id
ORDER BY invoice_id
