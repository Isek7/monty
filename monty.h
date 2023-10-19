#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int line_number;
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO ALX Project
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO AlX Project
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void (*get_func(char *ptr))(stack_t **top, unsigned int line_number);

void stack_push(stack_t **top, int val, int mode);
void stack_pall(stack_t **top, unsigned int line_number);
void stack_pint(stack_t **top, unsigned int line_number);
void stack_pop(stack_t **top, unsigned int line_number);
void stack_swap(stack_t **top, unsigned int line_number);
void stack_add(stack_t **top, unsigned int line_number);
void stack_nop(stack_t **top, unsigned int line_number);
void stack_sub(stack_t **top, unsigned int line_number);
void stack_div(stack_t **top, unsigned int line_number);
void stack_mul(stack_t **top, unsigned int line_number);
void stack_mod(stack_t **top, unsigned int line_number);
void stack_pchar(stack_t **top, unsigned int line_number);
void stack_pstr(stack_t **top, unsigned int line_number);
void stack_rotl(stack_t **top, unsigned int line_number);
void stack_rotr(stack_t **top, unsigned int line_number);

void free_stack(stack_t **top);

#endif /* MONTY */
