#include "monty.h"

/**
 * _set_queue - set is_q to 1
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _set_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	shared.is_q = 1;
}

/**
 * _set_stack - set is_q to 0
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _set_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	shared.is_q = 0;
}
