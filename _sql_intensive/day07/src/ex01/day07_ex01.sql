-- ex01
select 
	name,
	count(*) as count_of_visits
from person_visits pv inner join person p
on pv.person_id = p.id 
group by person_id, name
order by count_of_visits desc, person_id asc
limit 4