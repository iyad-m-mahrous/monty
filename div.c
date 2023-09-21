#include "monty.h"

/**
 * _div - divides the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		if ((*stack)->next)
		{
			if ((*stack)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				_free_all(stack);
				exit(EXIT_FAILURE);
			}
			(*stack)->next->n /= (*stack)->n;
			_pop(stack, line_number);
			return;
		}
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	_free_all(stack);
	exit(EXIT_FAILURE);
}
