select 
	name,
	count(*) as count_of_orders,
	round(avg(price), 2) as average_price,
	max(price) as max_price,
	min(price) as min_price
from person_order po inner join menu m
on po.menu_id = m.id inner join pizzeria p 
on m.pizzeria_id = p.id 
group by p.id, m.pizzeria_id
order by name