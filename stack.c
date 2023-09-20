#include "monty.h"

/**
 * _free_all - free all allocated memories and close file
 * @stack: pointer to the stack
 *
 * Return: void
 */
void _free_all(stack_t **stack)
{
	_free_stack(stack);
	free(shared.line_buff);
	fclose(shared.file);
}

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
	int arg_num = -1, i = 0, not_int = 0;

	if (shared.arg)
	{
		arg_num = atoi(shared.arg);
		if (shared.arg[0] == '-')
			i++;
		while (shared.arg[i])
		{
			if (shared.arg[i] < 48 || shared.arg[i] > 57)
			{
				not_int = 1;
				break;
			}
			i++;
		}
	}
	if (!shared.arg || not_int)
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
	pointer->n = atoi(shared.arg);
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

/**
 * _pop - pop data from stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}
/**
 * _pall - prints all data of stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * _pint - prints first data of stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		_free_all(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
