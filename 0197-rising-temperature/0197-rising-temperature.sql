with cte as
  (select  id, temperature, recordDate,
   lag(temperature) Over(order by recordDate) as temperature_new,
   lag(recordDate) Over(order by recordDate) as prev_date
   from Weather)

select id from cte
where temperature>temperature_new
and recordDate = DATE_ADD(prev_date, Interval 1 day)