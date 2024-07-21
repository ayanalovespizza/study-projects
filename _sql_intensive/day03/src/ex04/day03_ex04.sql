(select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join menu m 
	on pz.id = m.pizzeria_id
	inner join person_order po 
	on po.menu_id = m.id
	inner join person p
	on p.id = po.person_id
where gender = 'female'
except
select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join menu m 
	on pz.id = m.pizzeria_id
	inner join person_order po 
	on po.menu_id = m.id
	inner join person p
	on p.id = po.person_id
where gender = 'male')
union
(select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join menu m 
	on pz.id = m.pizzeria_id
	inner join person_order po 
	on po.menu_id = m.id
	inner join person p
	on p.id = po.person_id
where gender = 'male'
except
select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join menu m 
	on pz.id = m.pizzeria_id
	inner join person_order po 
	on po.menu_id = m.id
	inner join person p
	on p.id = po.person_id
where gender = 'female')
order by 1