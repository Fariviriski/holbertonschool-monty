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
	sub = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sub;
	free(temp);
}
