CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary from  (select DENSE_RANK() over (order by Salary desc) as r, Salary from Employee) as t where r =N    
  );
END
