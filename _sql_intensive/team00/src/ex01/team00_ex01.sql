WITH RECURSIVE travel(point_last, steps, cost, way) as (
    select distinct tsp.point1, 
          0,
          0, 
          tsp.point1
    from tsp
    where tsp.point1 = 'a'
  union all
    select tsp.point2, 
      travel.steps + 1, 
      travel.cost + tsp.cost, 
      travel.way || ',' || tsp.point2
    from tsp 
    inner join travel
    on travel.point_last = tsp.point1
    where travel.way not like '%' || tsp.point2 || '%' 
      or (tsp.point2 = 'a' and travel.steps = 3)
),
cheapest_tour as (
  select min(cost) as total_cost
  from travel
  where point_last = 'a' and steps = 4 
),

most_expensive_tour as (
  select max(cost) as total_cost
  from travel
  where point_last = 'a' and steps = 4 
),
union_tour as (
  select * 
  from cheapest_tour
  union all
  select * 
  from most_expensive_tour
)

select cost as total_cost, way as tour 
from travel 
inner join union_tour
on travel.cost = union_tour.total_cost
where point_last = 'a' and steps = 4 
order by cost, way;