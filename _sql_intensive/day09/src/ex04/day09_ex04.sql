create or replace function fnc_persons_female()
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
where gender = 'female';
$body$
language sql;

SELECT * FROM fnc_persons_female();

create or replace function fnc_persons_male()
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
	where gender = 'male';
$body$
language sql;

SELECT * FROM fnc_persons_male();