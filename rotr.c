#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
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
			temp->prev->next = NULL;
			temp->prev = NULL;
			temp->next = *stack;
			(*stack)->prev = temp;
			(*stack) = temp;
		}
}
