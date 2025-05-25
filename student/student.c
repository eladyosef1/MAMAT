#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <string.h>

student* student_clone(student *s){
	student *copy = malloc(sizeof(student));
	copy->name = strdup(*s->name);
	copy->age = s->age;
	copy->id = s->id;
	return copy;
}

void student_destroy(student *s){
	free(s);
}

void student_print(student *s){
	printf("student name: %s, age: %d, id: %d.\n", s->name, s->age, s->id);
}

