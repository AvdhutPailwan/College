/* 
Assignment No. 7
SQL Query Processing
Solves following SQL queries and display the result.
• Find the set of all courses taught either in Fall 2009 or in Spring 2010, or both.
• Find the set of all courses taught in the Fall 2009 as well as in Spring 2010.
• Find all courses taught in the Fall 2009 semester but not in the Spring 2010 semester.
• Find all the courses taught in the both the Fall 2009 and Spring 2010 semesters (Use set membership).
• Find all the courses taught in the Fall 2009 semester but not in the Spring 2010 semester (Use set membership).
• Find the names of all instructors whose salary is greater than at least one instructor in the Biology department.
• Find the names of all instructors that have a salary value greater than that of each instructor in the Biology department.
*/

-- • Find the set of all courses taught either in Fall 2009 or in Spring 2010, or both.
select course_id
from section
where sem = 'Fall' and year = 2009
union
select course_id
from section
where sem = 'Spring' and year = 2010;

-- • Find the set of all courses taught in the Fall 2009 as well as in Spring 2010.
select course_id
from section
where sem = 'Fall' and year = 2009
intersect
select course_id
from section
where sem = 'Spring' and year = 2010;

-- • Find all courses taught in the Fall 2009 semester but not in the Spring 2010 semester.
select course_id
from section
where sem = 'Fall' and year = 2009
except
select course_id
from section
where sem = 'Spring' and year = 2010;

-- • Find all the courses taught in the both the Fall 2009 and Spring 2010 semesters (Use set membership).
select course_id
from section
where sem = 'Fall' and year = 2009
intersect all
select course_id
from section
where sem = 'Spring' and year = 2010;

-- • Find all the courses taught in the Fall 2009 semester but not in the Spring 2010 semester (Use set membership).
select course_id
from section
where sem = 'Fall' and year = 2009
except all
select course_id
from section
where sem = 'Spring' and year = 2010;

-- • Find the names of all instructors whose salary is greater than at least one instructor in the Biology department.
select i_name
from instructor
where salary > some(select salary
                    from instructor 
                    where dept_name = 'Biology');

-- • Find the names of all instructors that have a salary value greater than that of each instructor in the Biology department.
select i_name
from instructor
where salary > all( select salary
                    from instructor
                    where dept_name = 'Biology');