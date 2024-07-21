create or replace function func_minimum(variadic arr numeric[])
	returns numeric as
$body$
declare 
	min_num numeric;
begin 
	select min(value) into min_num from unnest(arr) as value;
    return min_num;
end;
$body$
language plpgsql;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);