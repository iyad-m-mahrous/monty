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
	int arg_num = -1;

	if (shared.arg)
		arg_num = atoi(shared.arg);
	if (!shared.arg || (arg_num == 0 && strcmp(shared.arg, "0") != 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free_stack(stack);
		free(shared.line_buff);
		fclose(shared.file);
		exit(EXIT_FAILURE);
	}
	pointer = (stack_t *) malloc(sizeof(*pointer));
	if (!pointer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_stack(stack);
		free(shared.line_buff);
		fclose(shared.file);
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
		fclose(shared.file);
		free(shared.line_buff);
		_free_stack(stack);
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
