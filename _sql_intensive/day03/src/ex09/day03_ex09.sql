insert into person_visits values
	((select max(id) from person_visits) + 1, (select id from person where name = 'Denis'), (select id from pizzeria where name = 'Dominos'), '2022-02-24'),
	((select max(id) from person_visits) + 2, (select id from person where name = 'Irina'), (select id from pizzeria where name = 'Dominos'), '2022-02-24');
	
select * from person_visits;