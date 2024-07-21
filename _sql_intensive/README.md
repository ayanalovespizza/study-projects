# SQL Intensiv

![schema](schema.png)

1. **pizzeria** table (Dictionary Table with available pizzerias)
- field id - primary key
- field name - name of pizzeria
- field rating - average rating of pizzeria (from 0 to 5 points)
2. **person** table (Dictionary Table with persons who loves pizza)
- field id - primary key
- field name - name of person
- field age - age of person
- field gender - gender of person
- field address - address of person
3. **menu** table (Dictionary Table with available menu and price for concrete pizza)
- field id - primary key
- field pizzeria_id - foreign key to pizzeria
- field pizza_name - name of pizza in pizzeria
- field price - price of concrete pizza
4. **person_visits** table (Operational Table with information about visits of pizzeria)
- field id - primary key
- field person_id - foreign key to person
- field pizzeria_id - foreign key to pizzeria
- field visit_date - date (for example 2022-01-01) of person visit 
5. **person_order** table (Operational Table with information about persons orders)
- field id - primary key
- field person_id - foreign key to person
- field menu_id - foreign key to menu
- field order_date - date (for example 2022-01-01) of person order 

People's visit and people's order are different entities and don't contain any correlation between data. For example, a customer can be in a restaurant (just looking at the menu) and in that time place an order in another restaurant by phone or mobile application. Or another case, just be at home and again make a call with order without any visits.

Download a [script](model.sql) with Database Model here and apply the script to your database.

| Project             | Topics studied                                                 |
|:-------------------:|----------------------------------------------------------------|
| [Day00](day00)      | SELECT, WHERE, ORDER BY, CONCAT, Subquery, CASE (WHEN... ELSE) |
| [Day01](day01)      | UNION, INTERSECT, EXCEPT, JOINs (inner, natural), IN, EXISTS   |
| [Day02](day02)      | JOINs (left, right, full, ), GENERATE_SERIES, COALESCE, CTE    |
| [Day03](day03)      | INSERT, UPDATE, DELETE                                         |
| [Day04](day04)      | Virtual view and physical snapshot of data (CREATE VIEW)       |
| [Team00](team00)    | RECURSIVE                                                      |
| [Day05](day05)      | Database indexes (CREATE INDEX)                                |
| [Day06](day06)      | CREATE TABLE, CONSTRAINT, ROW_NUMBER() OVER                    |
| [Day07](day07)      | GROUP BY, HAVING, LIMIT, COUNT, MAX, MIN, AVG, ROUND,          |
| [Day08](day08)      | ACID properties, isolation levels, transactions                |
| [Day09](day09)      | CREATE TRIGGER, CREATE FUNCTION                                |
| [Team01](team10)    | first ETL process                                              |