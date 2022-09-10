#include "monty.h"
data_t datas = {NULL, NULL, NULL};
/**
*main - main function for monty interpreter
*@argc: argumnets  conuter
*@argv: arguments char
*Return: 0 on success
*/
int main(int argc, char **argv)
{
void (*temp)(stack_t **, unsigned int);
unsigned int line_number = 0;
char buf[BUFSIZ], *token;
datas.types = "stack";
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
datas.file = fopen(argv[1], "r");
if (datas.file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (fgets(buf, BUFSIZ, datas.file))
{
line_number++;
token = strtok(buf, " \t\n\r");
if (token == NULL || token[0] == '#')
continue;
if (check(token) == 1)
continue;
temp = opr(token);
if (!temp)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
free_memo(datas.list);
fclose(datas.file);
exit(EXIT_FAILURE);
}
temp(&datas.list, line_number);
}
free_memo(datas.list);
fclose(datas.file);
return (0);
}
/**
*opr - choose functions if exist
*@f1: function name
*Return: Nothing
*/
void (*opr(char *f1))(stack_t **head, unsigned int line_number)
{

instruction_t ops[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", addstack},
{"nop", nop},
{"sub", sub},
{"mul", mul},
{"div", divs},
{"mod", mods},
{"pchar", pchars},
{"pstr", pstrs},
{"rotl", rotls},
{"rotr", rotrs},
{NULL, NULL}
};
int i = 0;
while (ops[i].opcode)
{
if (strcmp(f1, ops[i].opcode) == 0)
break;
i++;
}
return (ops[i].f);
}
/**
 *check - for satck or queue
 *@token: token
 *Return: 1 if find or 0
 */
int  check(char *token)
{
if (strcmp(token, "queue") == 0)
{
datas.types = "queue";
return (1);
}
if (strcmp(token, "stack") == 0)
{
datas.types = "stack";
return (1);
}
return (0);
}
