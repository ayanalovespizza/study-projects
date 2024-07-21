select name
from 
	person p inner join person_order po 
	on p.id  = po.person_id 
	inner join menu m
	on m.id = po.menu_id 
where gender = 'male' and address in ('Moscow', 'Samara') and pizza_name in ('pepperoni pizza', 'mushroom pizza')
order by 1 desc