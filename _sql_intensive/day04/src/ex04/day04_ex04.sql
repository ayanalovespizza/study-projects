create view v_symmetric_union as
(select person_id from person_visits pv 
where visit_date = '2022-01-02'
except 
select person_id from person_visits pv 
where visit_date = '2022-01-06')
union
(select person_id from person_visits pv 
where visit_date = '2022-01-06'
except
select person_id from person_visits pv 
where visit_date = '2022-01-02')
order by 1;

select * from v_symmetric_union;