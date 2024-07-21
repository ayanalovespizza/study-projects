drop function fnc_persons_female();
drop function fnc_persons_male();

create or replace function fnc_persons(pgender varchar default 'female')
	returns table (
		id person.id%type,
		name person.name%type,
	  	age person.age%type,
	  	gender person.gender%type,
	  	address person.address%type
	 ) as
$body$
	select
		id, name, age, gender, address
	from person
	where gender = pgender;
$body$
language sql;
	
select * from fnc_persons(pgender := 'male');

select * from fnc_persons();