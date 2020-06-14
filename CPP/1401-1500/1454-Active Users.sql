/* Write your T-SQL query statement below */
select distinct a.id,a.name
from Logins l1 join Logins l2 on l1.id = l2.id and DATEADD(day,1,l1.login_date) = l2.login_date
join Logins l3 on l2.id = l3.id and DATEADD(day,1,l2.login_date) = l3.login_date
join Logins l4 on l3.id = l4.id and DATEADD(day,1,l3.login_date) = l4.login_date
join Logins l5 on l4.id = l5.id and DATEADD(day,1,l4.login_date) = l5.login_date
join Accounts a on l1.id = a.id
order by a.id
