create or replace function fnc_person_visits_and_eats_on_date(
	pperson varchar default 'Dmitriy',
	pprice numeric default 500,
	pdate date default '2022-01-08')
	returns table (
		pizzeria_name pizzeria.name%type		
	) as
$body$
begin
	return query
	select
		pz.name
	from pizzeria pz inner join menu m
	on m.pizzeria_id = pz.id inner join person_visits pv
	on pz.id = pv.pizzeria_id inner join person p
	on pv.person_id = p.id
	where p.name = pperson and m.price < pprice and visit_date = pdate;
end;
$body$
language plpgsql;

select * from fnc_person_visits_and_eats_on_date(pprice := 800);

select * from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');