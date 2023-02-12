# Write your MySQL query statement below

select e.employee_id from employees as e
left join 
salaries as s on e.employee_id=s.employee_id where salary is null
union
select s.employee_id from salaries as s
left join
employees as e on e.employee_id=s.employee_id where name is null
order by employee_id

# select e.employee_id from employees e  left join salaries s on e.employee_id=s.employee_id