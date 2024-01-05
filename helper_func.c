#include "monty.h"

/**
 *getf - gets function o to be used
 *@line: pointer to tokenizd input
 *@line_number: holds the line number of the file read
 *@g_stack: pointer tot stack
 *Return: function pointer
 */

void getf(m_stack_t **g_stack, char *line, unsigned int line_number)
{
	char *instruct = strtok(line, " \t\n$");
	int i;

	if (!instruct)
		return;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"pint", pint},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (!strcmp(instruct, instructions[i].opcode))
		{
			if (!strcmp(instruct, "push"))
			{
				char *arg = strtok(NULL, " \t\n$");

				if (!isInteger(arg))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				instructions[i].f(g_stack, atoi(arg));
			}
			else
				instructions[i].f(g_stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruct);
	exit(EXIT_FAILURE);
}
