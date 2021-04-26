#include <string.h>
#include <stdio.h>
#include <stdlib.h>		// For built-in malloc that returns void *

#include "Dictionary.h"
#include "Enrollment.h"

// create global dictionaries
dictionary	CourseDict;
dictionary	StudentDict;

// -------------------------------------------
// adds e to the CourseDict.
// Checks if e already exists, if so print error message
// and don't update the dictionary.  Else update dictionary.
// -------------------------------------------
void addCourse( course_element *e )
{
	// check if course already exists in dictionary
	if (find( CourseDict, (*e).key ) == NULL)
	    insert( CourseDict, (element *) e );		// add course to CourseDict
	else printf( "Course already exists.\n" );

	// alternative code:
	// if (insert( CourseDict, (element *) e ) == -1)
	// 	printf( "Course already exists.\n" );
}

// -------------------------------------------
// deletes course whose ID is c from the CourseDict.
// This should check if the course to be deleted exists.
// If not, just print an error message: "Course does not exist."
// and do not update both dictionaries.
// If the course exists, then this will also drop students who
// are currently enrolled // in the course i.e. StudentDict needs
// to be updated.  CourseDict needs to be updated as well.
// -------------------------------------------
void delCourse( char *c_key )
{


}

// -------------------------------------------
// enrolls student into course. params are s_key and c_key
// Need to check for: existence of course, and if student
// is already enrolled in the course.  Also check if course
// is full or if student has reached max number of courses.
// If there's any error, print a message and don't enroll
// the student.  If there's no errors, update both dictionaries.
// -------------------------------------------
enroll( char *s_key, char *c_key )
{
	course_value	*course_info;
	student_value	*student_info;

	node_t		*course_node;
	node_t		*student_node;

	// check if course already exists in dictionary
	course_info = find( CourseDict, c_key );		// get pointer to course_value field
	if (course_info == NULL)				// course does not exist
	    {
		printf( "Course does not exist.\n" );
		return;
	    }
	student_node = findList( course_info->list, s_key );
	if (student_node != NULL)				// student is already enrolled
	    {
		printf( "Student is already enrolled in that class.\n" );
		return;
	    }

	// add student to the course if there's space, update course_value field
	if ((*course_info).capacity == (*course_info).num_students)	// check capacity
	    {
		printf( "Course is full.\n" );
		return;
	    }
	else{
		student_node = (node_t *) malloc ( sizeof( node_t ) );
		memcpy( student_node->key, s_key, 5 );
		insertList( course_info->list, student_node );
		(*course_info).num_students++;
	     }

	// add course to the student if less than 2 enrolled, update student_value field
	if ((*student_info).num_courses == 2)		// already have max courses
	    {
		printf( "Cannot enroll in more than 2 courses.\n" );
		return;
	    }
	else{
		course_node = (node_t *) malloc ( sizeof( node_t ) );
		memcpy( course_node->key, c_key, 5 );
		insertList( student_info->list, course_node );
		(*student_info).num_courses++;
	    }
}

// -------------------------------------------
// drops a student from course. params are s_key and c_key
// Need to check for: existence of course, and if student
// is enrolled in the course.  If any error is encountered,
// print an error message.  Do not update either dictionaries.
// If there are no errors, update both dictionaries.
// -------------------------------------------
drop( char *s_key, char *c_key )
{


}

// -------------------------------------------
// prints the StudentDict.  For each student,
// list their courses.
// -------------------------------------------
void printStudents()
{
	printf("Students:\n");
	print( StudentDict );
}

// -------------------------------------------
// prints the CourseDict.  For each course,
// list the students enrolled.
// -------------------------------------------
void printCourses()
{
	printf("Courses:\n");
	print( CourseDict );
}

// -------------------------------------------
// Don't edit the code below.  This is the driver code to test
// your implementation.
// -------------------------------------------
main()
{
	char	line[100];
	char 	*command;
	int	done = 0;

        course_element  *ce;
        student_element *se;

	char	*course_key;
	char	*student_key;

	// initialize dictionaries
	create( CourseDict, 20 );
	create( StudentDict, 20 );

	// process input
	while( ! done )
	{
		// read an entire line as a string
		gets(line);

		// pulls command code, assume comma or tab separated
		command = strtok( line, " \t" );

		if (strcmp(command, "ex")==0)
			{	printf( "Bye\n" );
				done = 1;
			}
		else if (strcmp(command, "ac")==0)		// add a new course
			{
				// printf("ac\n");
				
				// Parse and package rest of line into a course_element
				ce = (course_element *) malloc( sizeof(course_element) );
				course_key = strtok( NULL, " " );
				printf( "Adding course: %s\n", course_key );
				memcpy( (*ce).key, course_key, 5 );
				ce->value = (void *) newNode( 'c' );
				ce->value->capacity = atoi( strtok( NULL, " " ) );
				ce->value->num_students = 0;
				ce->value->list = NULL;
				addCourse( ce );
			}
		else if (strcmp(command, "dc")==0)		// delete a course
			{
				// XXX
				printf("dc\n");
			}
		else if (strcmp(command, "en")==0)		// enroll a student
			{
				// printf("en\n");
				
				// Parse and package rest of line into a course_element
				student_key = strtok( NULL, " " );
				course_key = strtok( NULL, " " );
				printf( "Enrolling student: %s into course: %s\n", student_key, course_key );
				enroll( student_key, course_key ); 
			}
		else if (strcmp(command, "dr")==0)		// drop a student
			{
				// XXX
				printf("dr\n");
			}
		else if (strcmp(command, "ps")==0)		// print students
			printStudents();
		else if (strcmp(command, "pc")==0)		// print courses
			printCourses();
		else printf("Unrecognized command: %2s\n", command);

	}
}
