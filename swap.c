#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack)
		if ((*stack)->next)
		{
			temp = (*stack)->n;
			(*stack)->n = (*stack)->next->n;
			(*stack)->next->n = temp;
			return;
		}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	_free_all(stack);
	exit(EXIT_FAILURE);
}
