select
	order_date,
	concat (name, ' (age:', age, ')') as person_information
from
	(select id as person_id, name, age from person) natural join person_order 
order by order_date, person_information