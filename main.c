#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* tokenize - split the buf and store in the array
* @buf: buffer to be split.
* @arr: array store in buffer
*
* Return: Length of the array
*/

void tokenize(char *buf, char **arr)
{
arr[0] = strtok(buf, " \t\r\n");
arr[1] = strtok(NULL, " \t\r\n");
}

/**
* is_there_letter - check if there is a letter or istherealpha,
* an alphabet in a string.
*
* @s: string to check
*
* Return: 1 if True or ) if False
*/

int is_there_letter(char *s)
{
while (*s)
{
if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
return (1);
s++;
}

return (0);
}

/**
* execute_func - Executes the monty function
* @top: Stack
* @mode: Execution mode
* @arr: Tokenize values of the array
* @line: Line of execution
*
* Return: Terminate the program when no function is found
*/

void execute_func(stack_t **top, char **arr, int line, int mode)
{
int num;
void (*func)(stack_t **top, unsigned int number);

if (arr[1] != NULL)
num = atoi(arr[1]);
else
num = 0;

if (!arr[0] || arr[0][0] == '#')
return;

if (strcmp(arr[0], "push") == 0 && (!arr[1] || is_there_letter(arr[1])))
{
fprintf(stderr, "L%d: usage: push integer\n", line);
if (top)
free_stack(top);
exit(EXIT_FAILURE);
}

if (strcmp(arr[0], "push") == 0)
{
stack_push(top, num, mode);
return;
}

func = get_func(arr[0]);
if (func)
func(top, line);
else if (!func && strcmp(arr[0], "\n") != 0)
{

fprintf(stderr, "L%d: unknown instruction %s\n", line, arr[0]);
if (*top)
free_stack(top);
exit(EXIT_FAILURE);
}
}


/**
* main - Monty interpreter
* @argc: argurment count
* @argv: vector
*
* Return: success 0 or 1 on failure
*/

int main(int argc, char **argv)
{
int line_number = 0, mode = 1;
stack_t *top = NULL;
FILE *fp;
char buf[1024], *arr[100];
size_t buflen = 1024;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
fp = fopen(argv[1], "r");
if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
while (fgets(buf, buflen, fp) != NULL)
{
line_number++;

if (strcmp(buf, "\n") == 0)
continue;
if (strncmp(buf, "queue ", 6) == 0 || strcmp(buf, "queue\n") == 0)
{
mode = 0;
continue;
}
if (strncmp(buf, "stack ", 6) == 0 || strcmp(buf, "stack\n") == 0)
{
mode = 1;
continue;
}
tokenize(buf, arr);
execute_func(&top, arr, line_number, mode);
}
fclose(fp);
if (top)
free_stack(&top);
return (0);
}
