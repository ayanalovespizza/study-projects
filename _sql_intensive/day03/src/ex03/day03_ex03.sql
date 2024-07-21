-- для понимания задания: сохраняем дупликаты (all)
-- выбрать пиццерии, которые чаще посещали женщины и которые чаще посещали мужчины, объединить их
select pz.name, gender
	from 
		pizzeria pz inner join person_visits pv 
		on pz.id = pv.pizzeria_id 
		inner join person p 
		on pv.person_id = p.id
order by 1, 2;
-- отсюда понимаем, что Best Pizza чаще посещали мужчины, а Dominos, Papa Johns - женщины

-- само решение:
(select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p
	on pv.person_id = p.id
where gender = 'female'
except all
select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p
	on pv.person_id = p.id
where gender = 'male')
union all
(select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p
	on pv.person_id = p.id
where gender = 'male'
except all 
select 
	pz.name as pizzeria_name
from 
	pizzeria pz inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p
	on pv.person_id = p.id
where gender = 'female')
order by 1;