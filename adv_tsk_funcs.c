#include "monty.h"

/**
 * sub - subtracts top two elements of the stack.
 * @stack: pointer to stack.
 * @line_number: line number where "sub" appears.
 */

void sub(m_stack_t **stack, unsigned int line_number)
{
	int sub;
	m_stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->n - (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->n;
	(*stack)->next = sub;
	free(temp);
}
