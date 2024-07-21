-- добавляем новые записи в person_visits и person_order
insert into person_visits values
	((select count(*) from person_visits) + 1, 
	(select id from person where name = 'Dmitriy'), 
	(select id from pizzeria where name = 'DoDo Pizza'),
	'2022-01-08');

insert into person_order values
	((select count(*) from person_order) + 1,
	(select id from person where name = 'Dmitriy'), 
	(select id from menu where pizza_name = 'cheese pizza' and pizzeria_id = (select id from pizzeria where name = 'DoDo Pizza')),
	'2022-01-08');

-- обновляем материальное представление
refresh materialized view mv_dmitriy_visits_and_eats;
select * from mv_dmitriy_visits_and_eats;