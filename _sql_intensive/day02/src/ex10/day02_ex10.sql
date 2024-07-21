select person_name1, person_name2, table1.common_address
from (
	select 
		id,
		p.name as person_name1,
		p.address as common_address
	from person p
	) as table1 
	inner join
	(
	select 
		id, 
		p.name as person_name2,
		p.address as common_address
	from person p
	) as table2
	on table1.common_address = table2.common_address
where person_name1 != person_name2 and table1.id > table2.id 
order by 1, 2, 3