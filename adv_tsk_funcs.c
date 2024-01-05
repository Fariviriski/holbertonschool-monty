#include "monty.h"

/**
 * sub - subtracts top two elements of the stack.
 * @stack: pointer to stack.
 * @line_number: line number where "sub" appears.
 */

void sub(m_stack_t **stack, unsigned int line_number)
{
	int n;

	if (line_number < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}
