drop trigger trg_person_insert_audit on person;
drop trigger trg_person_update_audit on person;
drop trigger trg_person_delete_audit on person;

drop function fnc_trg_person_insert_audit();
drop function fnc_trg_person_update_audit();
drop function fnc_trg_person_delete_audit();

truncate person_audit; 
select * from person_audit;

create or replace function fnc_trg_person_audit()
	returns trigger as
$body$
begin 
	case 
		when tg_op = 'INSERT' then 
			insert into person_audit(created, type_event, row_id, name, age, gender, address)
			values (current_timestamp, 'I', new.id, new.name, new.age, new.gender, new.address);
		when tg_op = 'UPDATE' then 
			insert into person_audit(created, type_event, row_id, name, age, gender, address)
			values (current_timestamp, 'U', old.id, old.name, old.age, old.gender, old.address);
		when tg_op = 'DELETE' then 
			insert into person_audit(created, type_event, row_id, name, age, gender, address)
			values (current_timestamp, 'D', old.id, old.name, old.age, old.gender, old.address);
	end case;
	return null;
end;
$body$
language plpgsql;

create trigger trg_person_audit
after insert or update or delete on person
for each row 
execute function fnc_trg_person_audit();

INSERT INTO person(id, name, age, gender, address) 
VALUES (10,'Damir', 22, 'male', 'Irkutsk'); 

UPDATE person SET name = 'Bulat' WHERE id = 10; 
UPDATE person SET name = 'Damir' WHERE id = 10; 
DELETE FROM person WHERE id = 10;

select * from person;
select * from person_audit;