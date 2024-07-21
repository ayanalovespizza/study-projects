select 
	pizza_name,
	pizzeria.name as pizzeria_name,
	price
from (
	menu inner join pizzeria 
	on menu.pizzeria_id = pizzeria.id 
	)
where pizza_name = 'mushroom pizza' or pizza_name = 'pepperoni pizza'
order by 1, 2