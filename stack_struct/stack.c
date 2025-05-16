/*
 * stack.c
 *
 *  Created on: 16 May 2025
 *      Author: mamat
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


stack* stack_create(int capacity, clone_t clone,
		destroy_t destroy, print_t print){

	stack *new_stack = malloc(sizeof(stack));

	if(new_stack == NULL) return NULL;

	new_stack -> elements = malloc(capacity * sizeof(elem_t));
	if(new_stack -> elements == NULL){
		free(new_stack);
		return NULL;
	}

	new_stack -> size = 0;
	new_stack -> capacity = capacity;

	new_stack -> clone_elem = clone;
	new_stack -> destroy_elem = destroy;
	new_stack -> print_elem = print;

	return new_stack;
}

int stack_destroy(stack *S){

	if(S == NULL) return 0;

	if(S -> destroy_elem != NULL){
		for(int i = 0; i < S -> size; i++){
			if(S->elements[i] != NULL)
				S ->destroy_elem(S ->elements[i]);
		}
	}

	free(S ->elements);
	free(S);

	return 1;
}

int stack_push(stack *S, elem_t element){

	if(S==NULL || S->capacity == S->size) return 0;

	if(S->clone_elem != NULL){
		S->elements[S->size] = S->clone_elem(element);
	}

	if(S->elements[S->size] == NULL) return 0;

	S->size++;

	return 1;
}

void stack_pop(stack *S){
	if(S == NULL) printf("error occurred");


	else if(S->destroy_elem != NULL && S->elements[S->size-1] != NULL){
		S->destroy_elem( S->elements[S->size-1] );
		S->elements[S->size-1] = NULL; //is this required?
		S->size--;

	}else printf("error occurred");
}

elem_t* stack_peek(stack *S){
	elem_t *peeker;

	if(S == NULL || S->elements[S->size-1] == NULL || S->size <= 0) return NULL;

	peeker = &S->destroy_elem[S->size-1]; //is the '&' needed?

	return peeker;
}

int stack_size(stack *S){
	if(S == NULL) return 0;

	return S->size;
}

bool stack_is_empty(stack *S){
	if(S == NULL) return false;

	if(S->size != 0) return false;

	return true;
}

int stack_capacity(stack *S){
	if(S == NULL || S->capacity <= 0) return 0;

	return (S->capacity - S->size);
}

void stack_print(stack *S){
	if(S == NULL) return;
	if(stack_is_empty(S)) printf("Stack is empty");

	for(int i = S->size - 1; i >= 0; i--){
		if(S->print_elem != NULL){
			printf("  %d : ", S->size - i);
			S->print_elem(S->elements[i]);
	}
}



