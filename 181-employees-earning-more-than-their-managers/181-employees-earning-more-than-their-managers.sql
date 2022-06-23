select t1.name Employee 
from Employee t1 join Employee t2 on t1.managerId=t2.id
where  t1.salary>t2.salary