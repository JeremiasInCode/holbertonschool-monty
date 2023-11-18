#include "monty.h"

/**
* _pop - The opcode pop removes the top element of the stack.
*
* @stack: stack where work will be done.
* @line_number: number of lines.
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if ((*stack)->next == NULL && (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	*stack = (*stack)->next;
	free(node);
}

/**
* _swap - The opcode swap swaps the top two elements of the stack.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _swap(stack_t **stack, unsigned int line)
{
	stack_t *check = (*stack)->next;

	if (check->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	int tmp_n = (*stack)->n;
	stack_t *tmp = (*stack)->next;
	(*stack)->n = tmp->n;
	tmp->n = tmp_n;
}