#include "monty.h"

/**
 * main - main functuon
 * @argc: arguments
 * @argv: argument array
 * Return: int
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	m_stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		getf(&stack, line, line_number);
	}
	fclose(file);
	free_token(stack);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

/**
 * add - Add the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "add" opcode appears.
 */

void add(m_stack_t **stack, unsigned int line_number)
{
	int sum;
	m_stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n = sum;
	free(temp);
}

/**
 * nop - Do nothing.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "nop" opcode appears.
 */

void nop(m_stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This function does nothing, as it's a placeholder for a no-op */
}
/**
 * isInteger - Check if a string is a valid integer.
 * @str: The input string to be checked.
 * Return: 1 if @str is a valid integer, 0 otherwise.
 */
int isInteger(const char *str)
{
	if (!str || !*str || (*str != '-' && !isdigit(*str)))
		return (0);

	for (int i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
/**
 * free_token - Frees memory allocated for token array and token strings
 * @stack: The token array to be freed
 */
void free_token(m_stack_t *stack)
{
	m_stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = (stack)->next;
		free(current);
	}
}
