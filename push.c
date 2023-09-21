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
	int arg_num = 1, j = 0, flag = 0;

	if (shared.arg)
	{
		if (shared.arg[0] == '-')
			j++;
		for (; shared.arg[j] != '\0'; j++)
		{
			if (shared.arg[j] > 57 || shared.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(shared.file);
			free(shared.line_buff);
			_free_stack(stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(shared.file);
		free(shared.line_buff);
		_free_stack(stack);
		exit(EXIT_FAILURE); }
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
