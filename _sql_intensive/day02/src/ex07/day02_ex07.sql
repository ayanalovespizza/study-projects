select
	pz.name as pizzeria_name
from 
	menu m inner join pizzeria pz
	on m.pizzeria_id = pz.id 
	inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p
	on pv.person_id = p.id
where pv.visit_date = '2022-01-08' and p.name = 'Dmitriy' and m.price < 800