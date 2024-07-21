select 
	pizza_name,
	price, 
	pz.name as pizzeria_name
from 
	menu m inner join pizzeria pz
	on m.pizzeria_id = pz.id
	inner join 
	(select id as menu_id from menu
	except
	select menu_id from person_order
	order by 1) as table1
	on table1.menu_id = m.id
order by 1, 2