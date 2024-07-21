create view v_price_with_discount as
select 
	p.name as name,
	pizza_name,
	price,
	(price - price * 0.1)::bigint as discount_price
from 
	menu m inner join person_order po 
	on m.id = po.menu_id 
	inner join person p 
	on po.person_id = p.id
order by name, pizza_name;

select * from v_price_with_discount;