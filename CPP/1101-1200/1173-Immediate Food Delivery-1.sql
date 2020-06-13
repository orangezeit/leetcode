/* Write your T-SQL query statement below */
declare @total real;
select @total = count(*) from Delivery;

SELECT round(Cast(Count(*) as real) / @total * 100, 2) AS immediate_percentage
FROM Delivery
WHERE order_date = customer_pref_delivery_date;
