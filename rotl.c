#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *stack;
	if (temp)
		if (temp->next)
		{
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = (*stack);
			(*stack)->prev = temp;
			(*stack) = (*stack)->next;
			(*stack)->prev = NULL;
			temp->next->next = NULL;
		}
}
