CREATE TABLE employees21 (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    department VARCHAR(50),
    salary INT,
    age INT
);
INSERT INTO employees21 (name, department, salary, age) VALUES
('Anitha', 'IT', 60000, 25),
('Ravi', 'HR', 45000, 32),
('Sita', 'Finance', 70000, 29),
('Kiran', 'IT', 55000, 35),
('Meena', 'HR', 52000, 41);
SELECT * FROM employees21;
SELECT name,salary * 12 AS annual_salary,age % 2 AS age_remainder FROM employees21;
SELECT COUNT(*) AS total_employees,SUM(salary) AS total_salary,MAX(age) AS max_age FROM employees21;
SELECT SUM(salary * 12) AS total_annual_salary FROM employees21;
SELECT department,COUNT(*) AS employee_count,AVG(salary) AS avg_salary FROM employees21 GROUP BY department HAVING AVG(salary) > 50000;
