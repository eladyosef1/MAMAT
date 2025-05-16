/*
 * stack.h
 *
 *  Created on: 3 May 2025
 *      Author: mamat
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>


typedef void* elem_t;

typedef elem_t (*clone_t)(elem_t e);

typedef void (*destroy_t)(elem_t e);

typedef void (*print_t)(elem_t e);

typedef struct stack_t{

	/* regular fields of Stack */
	elem_t *elements;
	int size;
	int capacity;

	/* given pointers from the Question */
	clone_t clone_elem;
	destroy_t destroy_elem;
	print_t print_elem;

} stack;


/* Utility functions */
stack* stack_create(int capacity);

int stack_destroy(stack *S);

int stack_push(stack *S, elem_t element);

void stack_pop(stack *S);

elem_t* stack_peek(stack *S);

int stack_size(stack *S);

bool stack_is_empty(stack *S);

int stack_capacity(stack *S);

void stack_print(stack *S);


#endif /* STACK_H */
