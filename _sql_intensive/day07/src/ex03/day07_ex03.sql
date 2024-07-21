with ex02 as (
	(select 
		pz.name as name,
		count(*) as count,
		'visit' as action_type
	from person_visits pv inner join pizzeria pz
	on pv.pizzeria_id = pz.id
	group by name, pizzeria_id)
	union 
	(select
		pz.name as name,
		count(*) as count,
		'order' as action_type
	from pizzeria pz inner join menu m 
	on pz.id = m.pizzeria_id inner join person_order po 
	on m.id = po.menu_id
	group by m.pizzeria_id, pz.id))
select
	name,
	sum(count) as total_count
from ex02
group by name
order by total_count desc, name asc