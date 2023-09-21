#include "monty.h"

/**
 * _pchar - prints first data of stack as char
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
