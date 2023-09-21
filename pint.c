#include "monty.h"

/**
 * _pint - prints first data of stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
