with tmp_table as (
select 
	address,
	pz.name as name,
	count(*) as count_of_orders
from person p inner join person_order po 
on p.id = po.person_id inner join menu m 
on m.id = po.menu_id inner join pizzeria pz
on m.pizzeria_id = pz.id 
group by pz.name, p.id
order by address, name
)
select 
	address,
	name,
	sum(count_of_orders) as count_of_orders
from tmp_table
group by address, name