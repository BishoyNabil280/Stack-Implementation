/*
 * stack.h
 *
 *  
 *      Author: Bishoy Nabil
 */

#ifndef STACK_H_
#define STACK_H_

#include "compiler.h"

#define MAX 50
#define STACK_SIZE 20

typedef struct node
{
	uint8_t data;
	struct node *next;
}ST_node_t;

/* APIs */
void push(uint8_t u8_data);
uint8_t pull(void);
uint8_t Peek(void);
void printStack(void);
uint8_t* balancedParentheses(uint8_t* expression);

#endif /* STACK_H_ */
