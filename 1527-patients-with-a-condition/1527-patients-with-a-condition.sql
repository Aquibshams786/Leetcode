# Write your MySQL query statement below
select patient_id,patient_name,conditions from patients where conditions like 'DIAB1%' OR conditions like '% diab1%';
# substring(conditions,1,5)="DIAB1"
# where substring(conditions,1,4)='diab1';
