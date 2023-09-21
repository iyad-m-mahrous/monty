#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		if ((*stack)->next)
		{
			(*stack)->next->n += (*stack)->n;
			_pop(stack, line_number);
			return;
		}
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	_free_all(stack);
	exit(EXIT_FAILURE);
}
