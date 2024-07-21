(select 
	pz.name as name,
	count(*) as count,
	'visit' as action_type
from person_visits pv inner join pizzeria pz
on pv.pizzeria_id = pz.id
group by name, pizzeria_id
order by count desc
limit 3
)
union 
(select
	pz.name as name,
	count(*) as count,
	'order' as action_type
from pizzeria pz inner join menu m 
on pz.id = m.pizzeria_id inner join person_order po 
on m.id = po.menu_id
group by m.pizzeria_id, pz.id
order by count desc
limit 3
)	
order by action_type asc, count desc