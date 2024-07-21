-- ex00
create table person_audit (
	created timestamp with time zone not null default current_timestamp,
	type_event char(1) not null default 'I',
	row_id bigint not null,
	name varchar,
	age integer,
	gender varchar,
	address varchar,
	constraint ch_type_event check (type_event = 'I' or type_event = 'D' or type_event = 'U')
);

create or replace function fnc_trg_person_insert_audit() 
	returns trigger as
$body$
begin 
	insert into person_audit(created, type_event, row_id, name, age, gender, address)
	values (current_timestamp, 'I', new.id, new.name, new.age, new.gender, new.address);
	return null;
end;
$body$
language plpgsql;

create trigger trg_person_insert_audit 
after insert on person
for each row
execute function fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) 
VALUES (10,'Damir', 22, 'male', 'Irkutsk');

select * from person;
select * from person_audit;