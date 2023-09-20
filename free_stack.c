#include "monty.h"

/**
 * _free_stack - free the stack
 * @stack: pointer to the stack
 *
 * Return: Void
 */
void _free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		*stack = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}
