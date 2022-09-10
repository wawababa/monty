#include "monty.h"
/**
*rotls - rotates top of the elemenets
*@head: head of the list
*@value: line number
*Return: none
*/
void rotls(stack_t **head, __attribute__ ((unused)) unsigned int value)
{
stack_t *hold = *head;
int temp;
if (hold && hold->next)
{
while (hold->next != NULL)
{
temp = hold->n;
hold->n = hold->next->n;
hold->next->n = temp;
hold = hold->next;
}
}
}
/**
*rotrs - rotates top of the elemenets
*@stack: head of the list
*@value: line number
*Return: none
*/
void rotrs(stack_t **stack, __attribute__ ((unused)) unsigned int value)
{
stack_t *last;
if (*stack && (*stack)->next)
{
last = *stack;
while (last->next != NULL)
last = last->next;
last->prev->next = NULL;
last->next = *stack;
*stack = last;
}
}
