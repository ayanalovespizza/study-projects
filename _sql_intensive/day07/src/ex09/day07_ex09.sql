select 
	address,
	round(max(age * 1.0) - (min(age * 1.0) / max(age * 1.0)), 2) as formula,
	round(avg(age), 2) as average,
	case 
		when (max(age * 1.0) - (min(age * 1.0) / max(age * 1.0)) > avg(age)) then 'true'
		else 'false'
	end as comparison
from person p
group by address 
order by address