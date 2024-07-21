comment on table person_discounts is 'Personal discounts for people from one side and pizza restaurants from the other';
comment on column person_discounts.id is 'id attribute Primary Key - id of discount';
comment on column person_discounts.person_id  is 'person_id foreign keys for corresponding table (person) - id of person';
comment on column person_discounts.pizzeria_id  is 'pizzeria_id foreign keys for corresponding table (pizzeria) - id of pizzeria';
comment on column person_discounts.discount  is 'Calculate personal discount value by rule. If amount of orders equals 1 then 10.5 and etc.';
