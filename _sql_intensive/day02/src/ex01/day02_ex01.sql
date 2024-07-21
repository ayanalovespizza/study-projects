select gs::date as missing_date
from 
	(select * from person_visits 
	where person_id = 1 or person_id = 2) as visit_12 
	right join 
	generate_series('2022-01-01', '2022-01-10', interval '1 day') as gs
	on visit_12.visit_date = gs
where visit_12.id is null