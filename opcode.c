#include "monty.h"

/**
 *push - adds to the stack
 *@stack:a pointer to the head of the stack
 *@line_number:data to be stored
 */

void push(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *new_node;

	/* Allocate memory for a new stack node */
	new_node = malloc(sizeof(m_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the integer value in the new node */
	new_node->n = line_number;

	/* Initialize pointers for the new node */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Update the previous pointer of the current top element */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Update the stack pointer to point to the new top element */
	*stack = new_node;
}

/**
 *pall - print all opcode
 *@stack: array of data to print
 *@line_number: lines in input;
 */
void pall(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *current = *stack;

	/* Suppress unused parameter warning for line_number */
	(void)line_number;

	/* Traverse the stack and print each element */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *pint - prints the value @ the top of the stack
 *@stack: pointer to the stack
 *@line_number: unused param in this function
 */
void pint(m_stack_t **stack, unsigned int line_number)
{ /* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove item from stack
 * @stack: array of data
 * @line_number: line
 */
void pop(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *temp;

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save a pointer to the current top element */
	temp = *stack;

	/* Update the stack pointer to point to the next element */
	*stack = (*stack)->next;

	/* Update the previous pointer of the new top element to NULL */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	/* Free the memory of the removed element */
	free(temp);
}

/**
 * swap - swap top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void swap(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *temp;

	/* Check if there are at least two elements on the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save pointers to the top two elements */
	temp = (*stack)->next;

	/* Update the next pointers to perform the swap */
	(*stack)->next = temp->next;
	temp->next = *stack;

	/* Update the previous pointers to maintain the doubly linked list */
	temp->prev = NULL;
	(*stack)->prev = temp;

	/* Update the stack pointer to point to the new top element */
	*stack = temp;
}
