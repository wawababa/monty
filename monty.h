#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 *struct data - global usage
 *@file: file discriptor
 *@list: head of the list
 *@types: stack or queue
*/
typedef struct data
{
FILE *file;
stack_t *list;
char *types;
} data_t;
extern data_t datas;
void free_memo(stack_t *head);
void (*opr(char *f1))(stack_t **head, unsigned int line_number);
void push(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
stack_t *add(stack_t **head, int value);
stack_t *end(stack_t **head, int n);
void addstack(stack_t **head, unsigned int line_number);
void rotrs(stack_t **head, unsigned int value);
void sub(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void divs(stack_t **head, unsigned int line_number);
stack_t *add_end(stack_t **head, const int n);
void mods(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
int check(char *t);
void pchars(stack_t **head, unsigned int line_number);
void pstrs(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void rotls(stack_t **head, unsigned int line_number);
#endif
