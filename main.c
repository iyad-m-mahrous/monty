#include "monty.h"

shared_t shared = {NULL, NULL, NULL};

/**
 * main - Startup function
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 if OK otherwize 1
 */

int main(int argc, char *argv[])
{
	char *file_path;
	size_t len = 0;
	ssize_t nread;
	int line_no = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_path = argv[1];
	shared.file = fopen(file_path, "r");

	if (!shared.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	/*** add code her ***/

	while ((nread = getline(&(shared.line_buff), &len, shared.file)) != -1)
	{
		line_no++;
		_run(&stack, line_no);
		/** to be deleted **/
		/** End **/
	}
	free(shared.line_buff);
	_free_stack(&stack);



	/*** END ***/
	fclose(shared.file);
	return (0);
}
