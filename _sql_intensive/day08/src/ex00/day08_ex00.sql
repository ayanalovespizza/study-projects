-- Session #1 
begin;
update pizzeria set rating = 5 where name = 'Pizza Hut';
select * from pizzeria where name = 'Pizza Hut';
commit;

-- Session #2 
-- before commit in session #1
select * from pizzeria where name = 'Pizza Hut';

-- after commit in session #1
select * from pizzeria where name = 'Pizza Hut';