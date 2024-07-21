create view v_persons_female as
select * from person p
where gender = 'female';

select * from v_persons_female;

create view v_persons_male as
select * from person p
where gender = 'male';

select * from v_persons_male;