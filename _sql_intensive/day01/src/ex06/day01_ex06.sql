select 
	action_date,
	person.name as person_name
from (
	select 
		order_date as action_date,
		person_id
	from person_order
	intersect all
	select 
		visit_date as action_date,
		person_id 
	from person_visits
	) as date_n_id
	inner join person 
	on date_n_id.person_id = person.id 
order by action_date asc, person_name desc