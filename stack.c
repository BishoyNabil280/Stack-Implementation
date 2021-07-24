/*
 ============================================================================
 Name        : Stack.c
 Author      : Bishoy Nabil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"
#include "stack.h"

uint8_t length=0;
ST_node_t *top = NULL;

int main(void)
{
	uint8_t u8_buffer, u8_choice;
	uint8_t exp[MAX];
while(1)
{
	printf("             - Stack Application -\n");
	printf("Please select the operation:\n");
	printf(" 1-Push into Stack\n 2-Pop from Stack\n 3-Print Stack\n 4-Top element in Stack\n 5-Balanced Expression Check\n");
	fflush(stdout);
	scanf("%d",&u8_choice);
	fflush(stdin);
	switch(u8_choice)
	{
	case 1:
		printf("Enter the number you want to push into Stack: \n");
		fflush(stdout);
		scanf("%d",&u8_buffer);
		push(u8_buffer);
		break;
	case 2:
		u8_buffer=pull();
		printf("Popped Element is: %d\n",u8_buffer);
		fflush(stdout);
		break;
	case 3:
		printStack();
		break;
	case 4:
		u8_buffer=Peek();
		printf("Top Element is: %d\n",u8_buffer);
		fflush(stdout);
		break;
	case 5:
		printf("Please insert your expression: \n");
		fflush(stdout);
		gets(exp);
		fflush(stdin);
		printf("%s\n",balancedParentheses(exp));
		fflush(stdout);
		break;
	default:
		printf("Wrong Entry!\n");
		fflush(stdout);
	}
}
	return 0;
}

void push(uint8_t u8_data)
{
	if(length==STACK_SIZE)
	{
		printf("Stack is Full!\n");
		fflush(stdout);
		return;
	}else
	{
		ST_node_t *link = (ST_node_t*) malloc(sizeof(ST_node_t));
		link->data = u8_data;
		link->next = top;
		top = link;
		length++;
	}
}


uint8_t pull(void)
{
	uint8_t temp;
	ST_node_t *deleted_node = top;
	temp=top->data;
	if(top == NULL)
	{
		printf("Stack is Empty!\n");
		fflush(stdout);
		return;
	}
	top = top->next;
	free(deleted_node);
	length--;
	return temp;
}

uint8_t Peek(void)
{
	return top->data;
}


void printStack(void)
{
	ST_node_t *ptr = top;
	printf("[top] =>");
	while(ptr != NULL)
	{
		printf(" %d =>",ptr->data);
		ptr = ptr->next;
	}
	printf(" [null]\n");
}


uint8_t* balancedParentheses(uint8_t* expression)
{
	uint8_t i = 0;
	for(i=0;i<strlen(expression);i++)
	{
		if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
		{
			push(expression[i]);
			continue;
		}
		else if(expression[i]==')' || expression[i]==']' || expression[i]=='}')
		{
			if(expression[i]==')')
			{
				if(Peek()== '(')
				{
					pull();
				}
				else
				{
					return "Not Balanced";
				}
			}
			if(expression[i]==']')
			{
				if(Peek()=='[')
				{
					pull();
				}
				else
				{
					return "Not Balanced";
				}
			}
			if(expression[i]=='}')
			{
				if(Peek()=='{')
				{
					pull();
				}
				else
				{
					return "Not Balanced";
				}
			}
		}
	}
	if(length==0)
		return "Balanced";
}
