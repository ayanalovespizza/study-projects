create or replace function fnc_fibonacci(pstop integer default 10)
	returns table (fibonacci_number bigint) as
$body$
with recursive fib_func(num1, num2) as (
    select 0 as num1, 1 as num2
    union all
    select num2, num1 + num2
    from fib_func
    where num2 < pstop)
select num1 from fib_func;
$body$
language sql;

select * from fnc_fibonacci(100);
select * from fnc_fibonacci();