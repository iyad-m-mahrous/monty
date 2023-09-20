#include "monty.h"

/**
 * _run - runs a line of a code
 * @stack: pointer to the stack
 * @line_no: line number
 *
 * Return: Void
 */
void _run(stack_t **stack, int line_no)
{
	char *command;
	int i = 0;
	instruction_t funcs[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall", _pall},
		{NULL, NULL}
	};

	command = strtok(shared.line_buff, " \t\n");
	if (!command)
		return;
	if (command[0] == '#')
		return;
	shared.arg = strtok(NULL, " \t\n");
	while (funcs[i].opcode)
	{
		if (strcmp(command, funcs[i].opcode) == 0)
		{
			funcs[i].f(stack, line_no);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, command);
	free(shared.line_buff);
	fclose(shared.file);
	_free_stack(stack);
	exit(EXIT_FAILURE);
}
