# Write your MySQL query statement below

SELECT month, country, SUM(CASE WHEN state = "approved" THEN 1 ELSE 0 END) AS approved_count, SUM(CASE WHEN state = "approved" THEN amount ELSE 0 END) AS approved_amount, SUM(CASE WHEN state = "back" THEN 1 ELSE 0 END) AS chargeback_count, SUM(CASE WHEN state = "back" THEN amount ELSE 0 END) AS chargeback_amount
FROM
(
    SELECT LEFT(chargebacks.trans_date, 7) AS month, country, "back" AS state, amount
    FROM chargebacks
    JOIN transactions ON chargebacks.trans_id = transactions.id
    UNION ALL
    SELECT LEFT(trans_date, 7) AS month, country, state, amount
    FROM transactions
    WHERE state = "approved"
) s
GROUP BY month, country
