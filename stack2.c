#include "monty.h"
#include <stdlib.h>

/**
* stack_add - it add the first two node value of the stack,
* and delete the top node.
* @top: stack
* @line_number: The present line of execution
*
* Return: Nothing
*/
void stack_add(stack_t **top, unsigned int line_number)
{
stack_t *next;

if (!top || !(*top) || !((*top)->next))
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
next->n = next->n + (*top)->n;
free(*top);
*top = next;
}


/**
* stack_nop - it performs no operation.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_nop(stack_t **top, unsigned int line_number)
{
(void)line_number;
(void)top;
}


/**
* stack_sub - it subtract the first node value from the second node,
* value of the stack and delete the top node.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_sub(stack_t **top, unsigned int line_number)
{
stack_t *next;

if (!top || !(*top) || !((*top)->next))
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
next->n = next->n - (*top)->n;
free(*top);
*top = next;
}


/**
* stack_div - it divids the first node value from the second node value,
* of the stack and delete the top node.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_div(stack_t **top, unsigned int line_number)
{
stack_t *next;

if (!top || !(*top) || !((*top)->next))
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*top)->n == 0)
{

fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
next->n = next->n / (*top)->n;
free(*top);
*top = next;
}
