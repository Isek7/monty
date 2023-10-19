#include "monty.h"
#include <stdio.h>
#include <stdlib.h>


/**
* stack_push - it add a node at the top of the stack
* @top: stack
* @val: present line in the monty file
* @mode: execution mode
*
* Return: Nothing
*/
void stack_push(stack_t **top, int val, int mode)
{
stack_t *node, *curr;

if (!top)
return;

node = malloc(sizeof(*node));

if (!node)
{
free(node);
node = NULL;
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

node->n = val;
node->next = NULL;
node->prev = NULL;

if (!(*top))
{
*top = node;
return;
}

if (mode)
{
(*top)->prev = node;
node->next = *top;
*top = node;
}
else
{
curr = *top;
while (curr->next)
curr = curr->next;
node->prev = curr;
curr->next = node;
}

}

/**
* stack_pall - it print all nodes in the stack
* @top: stack
* @line_number: present line in the monty file
*
* Return: Nothing
*/
void stack_pall(stack_t **top, unsigned int line_number)
{
stack_t *curr;

(void)line_number;

if (!top)
return;

curr = *top;

while (curr)
{
printf("%d\n", (curr)->n);
curr = curr->next;
}

}

/**
* free_stack - it frees all nodes from memory
* @top : stack
*
* Return: Nothing
*/
void free_stack(stack_t **top)
{
if (!top)
return;

while (*top)
{
stack_t *next = (*top)->next;

free(*top);
*top = next;
}

if (*top != NULL)
*top = NULL;
}

/**
* stack_pint - it prints the first node value of the stack
* @top: stack
*
* @line_number: The present line of execution
* Return: Nothing
*/
void stack_pint(stack_t **top, unsigned int line_number)
{

if (!top || !(*top))
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*top)->n);
}
