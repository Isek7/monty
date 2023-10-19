#include "monty.h"

/**
* stack_pop - it remove the first node value of the stack
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_pop(stack_t **top, unsigned int line_number)
{
stack_t *next;

if (!top || !(*top))
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
free(*top);
*top = next;
}

/**
* stack_swap - it swaps the first two node value of the stack
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_swap(stack_t **top, unsigned int line_number)
{
stack_t *next;
int isek;

if (!top || !(*top) || !((*top)->next))
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
isek = (*top)->n;
(*top)->n = next->n;
next->n = isek;
}

/**
* stack_rotl - it makes the first node the last node.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_rotl(stack_t **top, unsigned int line_number)
{
stack_t *curr;
int val;

(void)line_number;

if (!top || !(*top) || !((*top)->next))
return;

curr = *top;

while (curr->next)
{

val = curr->n;
curr->n = curr->next->n;
curr->next->n = val;
curr = curr->next;
}
}

/**
* stack_rotr - it makes the last node as the first element.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_rotr(stack_t **top, unsigned int line_number)
{
stack_t *curr;

(void)line_number;

if (!top || !(*top) || !((*top)->next))
return;

curr = *top;

while (curr->next != NULL)
curr = curr->next;

curr->prev->next = NULL;
curr->next = *top;
curr->prev = NULL;
*top = curr;
}
