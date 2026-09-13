# Write your MySQL query statement below

select n.name as name  , b.bonus as bonus from Employee as n left join Bonus as b on n.empId = b.empid where b.bonus<1000 or b.bonus is NULL;