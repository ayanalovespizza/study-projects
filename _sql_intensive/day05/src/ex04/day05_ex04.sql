create index idx_menu_unique on menu(pizzeria_id, pizza_name);
set enable_seqscan = off;
explain analyze
select * from menu
where pizzeria_id = 2 and pizza_name = 'supreme pizza'