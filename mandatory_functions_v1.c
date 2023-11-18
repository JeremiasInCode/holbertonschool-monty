#include "monty.h"

/**
* _push - The opcode push pushes an element to the stack.
*
* @stack: stack where work will be done.
* @line_number: number of lines.
*/

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	char *token_number = NULL;

	/* ! Numero para agregar a la pila. */
	token_number = strtok(NULL, " \t\n$");
	if (!token_number || is_number(token_number) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	/*
	* ! Conectamos el nuevo nodo al stack (head) este mismo
	* se lo asignamos al newNode para que sea el primer elmento en la pila.
	*/
	newNode->n = atoi(token_number);
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack)
	{
		(*stack)->prev = newNode;
	}
	(*stack) = newNode;
}
