/* 
Assignment No. 8
SQL Query Processing Solves the following SQL queries and display the result.
• Find the average salary of instructors in the Computer Science department.
• Find the total number of instructors who teach a course in the Spring 2010 semester.
• Find the number of tuples in the course relation.
• Find the average salary in each department.
• Find the average salary of those departments where the average salary is more than $42,000.
• Find total all salary amounts.
• Find the departments that have the highest average salary
• Create a view that lists all course sections offered by the Physics department in the Fall 2009 semester with the building and room number of each section.
• Create an index on instructor with i_id as search key.
*/

-- • Find the average salary of instructors in the Computer Science department.
select avg(salary)
from instructor
where dept_name = 'Comp. Sci.';

-- • Find the total number of instructors who teach a course in the Spring 2010 semester.
select count(distinct i_id)
from teaches
where sem = 'Spring' and year = 2010;

-- • Find the number of tuples in the course relation.
select count(*)
from course;
-- • Find the average salary in each department.
select avg(salary), dept_name
from instructor
group by dept_name;
-- • Find the average salary of those departments where the average salary is more than $42,000.
select avg(salary), dept_name
from instructor
group by dept_name
having avg(salary) > 42000;
-- • Find total all salary amounts.
select sum(salary)
from instructor;
-- • Find the departments that have the highest average salary
select dept_name
from instructor
group by dept_name
having avg(salary) >= all(select avg(salary)
						  from instructor
						  group by dept_name);
-- • Create a view that lists all course sections offered by the Physics department in the Fall 2009 semester with the building and room number of each section.
create view phyCourses as
select sec_id, building, room_no
from section natural join course
where dept_name = 'Physics' and sem = 'Fall' and year = 2009;
-- • Create an index on instructor with i_id as search key.
create index _id on instructor(i_id);
