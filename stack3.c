#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* stack_mul - it multiply the first value with the second value of the,
* stack and delete the top node.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_mul(stack_t **top, unsigned int line_number)
{
stack_t *next;

if (!top || !(*top) || !((*top)->next))
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
next->n = next->n * (*top)->n;
free(*top);
*top = next;
}

/**
* stack_mod - it find the mod of the first value from the second,
* value of the stack and delete the top node.
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_mod(stack_t **top, unsigned int line_number)
{
stack_t *next;

if (!top || !(*top) || !((*top)->next))
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*top)->n == 0)
{

fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

next = (*top)->next;
next->n = next->n % (*top)->n;
free(*top);
*top = next;
}

/**
* stack_pchar - it prints the value at the top of stack as character
*
* @top: stack
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_pchar(stack_t **top, unsigned int line_number)
{
int val;

if (!top || !(*top))
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

val = (*top)->n;

if (val >= 0 && val <= 127)
{
putchar(val);
putchar('\n');
}
else
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
}

/**
* stack_pstr - it prints the ascii value of all nodes at the stack
*
* @top: stack
* @line_number: Present line of execution
* Return: Nothing
*/
void stack_pstr(stack_t **top, unsigned int line_number)
{
int val;
stack_t *curr;

(void)line_number;

if (!top || !(*top))
{
putchar('\n');
return;
}

curr = *top;

while (curr && curr->n)
{
val = curr->n;

if (val >= 0 && val <= 127)
putchar(val);
else
break;
curr = curr->next;
}

putchar('\n');
}
