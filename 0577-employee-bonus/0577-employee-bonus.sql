# Write your MySQL query statement below
select name, bonus
from employee e LEFT JOIN bonus b on e.empId = b.empId 
where bonus < 1000 or bonus is null;