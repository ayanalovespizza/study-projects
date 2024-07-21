insert into person_order 
select 
	gs + (select max(id) from person_order) as id,
	id as person_id,
	(select id from menu where pizza_name = 'greek pizza') as menu_id,
	'2022-02-25' as order_date
from 
	person inner join generate_series(1, (select max(id) from person)) as gs
	on gs = person.id;

select * from person_order po;