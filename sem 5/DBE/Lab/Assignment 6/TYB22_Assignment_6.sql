/*
Assignment No. 6
SQL Query Processing
Solves following SQL queries and display the result.
• Find the names of all instructors of Comp. Sci. department with salary between $90,000
and $100,000.
• Retrieve the names of all instructors, along with their department names and department
building name.
• Find instructor names and course identifiers for instructors in the Computer Science
department.
• For all instructors in the university who have taught some course, find their names and
the course ID of all courses they taught (use natural join).
• List in alphabetic order all instructors in the Physics department.
• List the entire instructor relation in descending order of salary.
*/

-- • Find the names of all instructors of Comp. Sci. department with salary between $90,000 and $100,000.
select i_name
from instructor
where dept_name = 'Comp. Sci.' and salary between 90000 and 100000;

-- • Retrieve the names of all instructors, along with their department names and department building name.
select i_name, dept_name, building
from instructor natural join department;

-- • Find instructor names and course identifiers for instructors in the Computer Science department.
select i_name, course_id
from instructor natural join course
where dept_name = 'Comp. Sci.';

-- • For all instructors in the university who have taught some course, 
-- find their names and the course ID of all courses they taught (use natural join).
select i_name, course_id
from instructor natural join course
order by i_name;

-- • List in alphabetic order all instructors in the Physics department.
select *
from instructor
where dept_name = 'Physics'
order by i_name;

-- • List the entire instructor relation in descending order of salary.
select * from instructor order by salary desc;

