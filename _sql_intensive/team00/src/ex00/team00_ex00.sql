create table tsp (
  point1 varchar not null,
  point2 varchar not null,
  cost integer not null
);

insert into tsp values
  ('a', 'b', 10),
  ('a', 'c', 15),
  ('a', 'd', 20),
  ('b', 'a', 10),
  ('b', 'c', 35),
  ('b', 'd', 25),
  ('c', 'a', 15),
  ('c', 'b', 35),
  ('c', 'd', 30),
  ('d', 'a', 20),
  ('d', 'b', 25),
  ('d', 'c', 30);

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
)

select cost as total_cost, way as tour 
from travel 
inner join cheapest_tour
on travel.cost = cheapest_tour.total_cost
where point_last = 'a' and steps = 4 
order by cost, way;