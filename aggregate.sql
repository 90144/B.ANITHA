CREATE USER 'staff_user'@'localhost' IDENTIFIED BY 'password123';
GRANT SELECT ON employees21 TO 'staff_user'@'localhost';
SHOW GRANTS FOR 'staff_user'@'localhost';
INSERT INTO employees21 (name, department, salary, age)VALUES ('Test', 'IT', 50000, 30);
GRANT INSERT ON employees21 TO 'staff_user'@'localhost';
INSERT INTO employees21 (name, department, salary, age)VALUES ('Test', 'IT', 50000, 30);
REVOKE INSERT ON employees21 FROM 'staff_user'@'localhost';
SHOW GRANTS FOR 'staff_user'@'localhost';

CREATE TABLE accounts (
    acc_id INT PRIMARY KEY,
    name VARCHAR(50),
    balance INT
);
INSERT INTO accounts VALUES (1, 'Anitha', 10000);
START TRANSACTION;
UPDATE accounts SET balance = balance - 2000 WHERE acc_id = 1;
SELECT * FROM accounts;
ROLLBACK;
SELECT * FROM accounts;
START TRANSACTION;
UPDATE accounts SET balance = balance - 2000 WHERE acc_id = 1;
COMMIT;
SELECT * FROM accounts;
