# Write your MySQL query statement below

select customers.name as Customers from customers
left join orders
on customers.id=orders.customerId
where orders.Id is null;
