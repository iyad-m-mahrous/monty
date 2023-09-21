#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *stack;
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
