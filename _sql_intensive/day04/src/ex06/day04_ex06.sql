-- представления не хранят данные, при обращении к ним данные извлекаются из таблиц
-- материализованные представления выполняют запрос один раз и хранят данные
create materialized view mv_dmitriy_visits_and_eats as
select
	pz.name as pizzeria_name
from 
	menu m inner join pizzeria pz
	on m.pizzeria_id = pz.id 
	inner join person_visits pv 
	on pz.id = pv.pizzeria_id 
	inner join person p
	on pv.person_id = p.id
where pv.visit_date = '2022-01-08' and p.name = 'Dmitriy' and m.price < 800;

select * from mv_dmitriy_visits_and_eats;