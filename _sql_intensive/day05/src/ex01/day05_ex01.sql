set enable_seqscan = off;
explain analyse
select 
	pizza_name,
	p.name as pizzeria_name
from menu m inner join pizzeria p 
on m.pizzeria_id = p.id