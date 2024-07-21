select 
	pizza_name, 
	pizzeria.name as pizzeria_name
from (
	person_order inner join menu on person_order.menu_id = menu.id
	inner join pizzeria 
	on pizzeria_id = pizzeria.id 
	inner join person
	on person_id = person.id
	)
where person.name = 'Denis' or  person.name = 'Anna'
order by 1, 2