select p.name 
from person p inner join person_order po 
on p.id = po.person_id 
group by p.id, po.person_id
order by 1