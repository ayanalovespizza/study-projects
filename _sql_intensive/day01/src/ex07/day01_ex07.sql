select
	order_date,
	concat (name, ' (age:', age, ')') as person_information
from
	person inner join person_order
	on person_order.person_id = person.id
order by order_date, person_information