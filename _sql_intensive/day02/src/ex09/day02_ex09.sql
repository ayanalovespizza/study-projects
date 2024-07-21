select name
from 
	person p inner join person_order po 
	on p.id = po.person_id 
	inner join menu m 
	on po.menu_id = m.id 
where gender = 'female' and pizza_name in ('pepperoni pizza')
intersect 
select name
from 
	person p inner join person_order po 
	on p.id = po.person_id 
	inner join menu m 
	on po.menu_id = m.id 
where gender = 'female' and pizza_name in ('cheese pizza')
order by 1