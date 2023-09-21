#include "monty.h"

/**
 * _push - push int to stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
	int arg_num = 1, i = 0, is_int = 1;

	if (shared.arg)
	{
		arg_num = atoi(shared.arg);
		if (shared.arg[0] == '-')
			i++;
		while (shared.arg[i])
		{
			if (shared.arg[i] < 48 || shared.arg[i] > 57)
				is_int = 0;
			i++;
		}
	}
	if (!shared.arg || !is_int)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	pointer = (stack_t *) malloc(sizeof(*pointer));
	if (!pointer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	pointer->n = arg_num;
	pointer->prev = NULL;
	pointer->next = NULL;
	if (!(*stack))
		*stack = pointer;
	else
	{
		pointer->next = *stack;
		(*stack)->prev = pointer;
		*stack = pointer;
	}
}
