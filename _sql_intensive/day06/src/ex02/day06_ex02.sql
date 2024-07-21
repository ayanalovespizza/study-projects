select 
	p.name as name, 
	pizza_name, 
	price, 
	(price - (price * discount/100) ) as discount_price, 
	pz.name as pizzeria_name 
from person_order inner join menu m 
on m.id = person_order.menu_id inner join person p 
on p.id = person_order.person_id inner join person_discounts pd 
on p.id = pd.person_id and pd.pizzeria_id = m.pizzeria_id inner join pizzeria pz 
on m.pizzeria_id = pz.id 
order by name, pizza_name