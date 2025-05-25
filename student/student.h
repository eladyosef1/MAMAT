#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
	char *name;
	int age;
	int id;
} student;

student* student_clone(student *s);
void student_destroy(student *s);
void student_print(student *s);

#endif