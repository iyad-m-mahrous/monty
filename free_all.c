#include "monty.h"

/**
 * _free_all - frees all allocated memory and close file
 * @stack: pointer to the stack
 *
 * Return: void
 */
void _free_all(stack_t **stack)
{
	free(shared.line_buff);
        _free_stack(stack);
        fclose(shared.file);
}
