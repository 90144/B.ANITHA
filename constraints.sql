
CREATE TABLE Student112 (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    Age INT CHECK (Age >= 18),
    IsActive BOOLEAN DEFAULT TRUE
);
show tables;
describe Student112;
INSERT INTO Student112 (StudentID, Name, Email, Age)
VALUES 
(1, 'Anitha', 'anitha@gmail.com', 20),
(2, 'Rahul', 'rahul@gmail.com', 22),
(3, 'Sneha', 'sneha@gmail.com', 19);
INSERT INTO Student112 (StudentID, Name, Email, Age)
VALUES (4, NULL, 'test@gmail.com', 20);
INSERT INTO Student112 (StudentID, Name, Email, Age)
VALUES (5, 'Kiran', 'anitha@gmail.com', 21);
INSERT INTO Student112 (StudentID, Name, Email, Age)
VALUES (6, 'Teja', 'teja@gmail.com', 16);

CREATE TABLE Enrollments (
    EnrollmentID INT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    Credits INT CHECK (Credits BETWEEN 1 AND 5),
    StudentID INT,
    EnrollmentDate DATE ,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID)
);

INSERT INTO Enrollments (EnrollmentID, CourseName, Credits, StudentID)
VALUES
(101, 'Database Systems', 4, 1),
(102, 'Python Programming', 3, 2),
(103, 'Data Structures', 5, 3);
INSERT INTO Enrollments (EnrollmentID, CourseName, Credits, StudentID)
VALUES (105, 'ML', 6, 1);
INSERT INTO Enrollments (EnrollmentID, CourseName, Credits, StudentID)
VALUES (104, 'AI', 3, 10);


