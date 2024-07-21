-- with IN
select name from pizzeria
where id not in (select pizzeria_id from person_visits)

-- with EXISTS
select name from pizzeria
where not exists(
	select id from person_visits pv
	where pv.pizzeria_id = pizzeria.id)