(select pz.name as pizzeria_name
from 
	pizzeria pz inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p 
	on p.id = pv.person_id 
where p.name = 'Andrey')
except
(select pz.name as pizzeria_name
from 
	pizzeria pz inner join menu m
	on m.pizzeria_id = pz.id 
	inner join person_order po 
	on m.id = po.menu_id
	inner join person p
	on p.id = po.person_id
where p.name = 'Andrey')