#include "monty.h"

/**
* get_func - A pointer to a function that takes a char as an argument
* @ptr: pointer
* Return: Success or NULL on Failure
*/
void (*get_func(char *ptr))(stack_t **top, unsigned int line_number)
{
instruction_t inst[] = {
{"pall", stack_pall},
{"pint", stack_pint},
{"pop", stack_pop},
{"swap", stack_swap},
{"add", stack_add},
{"nop", stack_nop},
{"sub", stack_sub},
{"div", stack_div},
{"mul", stack_mul},
{"mod", stack_mod},
{"pchar", stack_pchar},
{"pstr", stack_pstr},
{"rotl", stack_rotl},
{"rotr", stack_rotr},
};

const int LEN = 14;
int i = 0;

while (i < LEN)
{
if (strcmp(ptr, inst[i].opcode) == 0)
return (inst[i].f);
i++;
}

return (NULL);
}
