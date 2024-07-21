select 
	pizza_name, 
	price, 
	pz.name as pizzeria_name, 
	visit_date
from 
	person p inner join person_visits pv 
	on p.id = pv.person_id 
	inner join pizzeria pz
	on pv.pizzeria_id = pz.id 
	inner join menu m
	on m.pizzeria_id = pz.id 
where p.name = 'Kate' and price between 800 and 1000
order by 1, 2, 3