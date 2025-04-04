select left(trans_date,7) as month, # or dateformat(trans_date,'%Y-%m')
country,
count(id) as trans_count,
sum(if(state='approved',1,0)) as approved_count,
sum(amount) as trans_total_amount,
sum(if(state='approved',amount,0)) as approved_total_amount
from transactions
group by month,country