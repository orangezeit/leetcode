with cte as
( select
    duration/60 as mins
 from sessions
)

select
    '[0-5>' as bin,
    sum(case when mins >= 0 and mins < 5 then 1 else 0 end) as total
from cte
union all
select
    '[5-10>' as bin,
    sum(case when mins >= 5 and mins < 10 then 1 else 0 end) as total
from cte
union all
select
    '[10-15>' as bin,
    sum(case when mins >= 10 and mins < 15 then 1 else 0 end) as total
from cte
union all
select
    '15 or more' as bin,
    sum(case when mins >= 15 then 1 else 0 end) as total
from cte
