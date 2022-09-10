#include "monty.h"
/**
*push_q - add node at the end
*@head: head of the list
*@n: number
*Return: address of the head
*/
stack_t *end(stack_t **head, int n)
{
stack_t *dark, *hold;
dark = malloc(sizeof(stack_t));
if (dark == NULL)
return (NULL);
dark->n = n;
dark->next = NULL;
dark->prev = NULL;
if (*head == NULL)
*head = dark;
else
{
hold = *head;
while (hold->next != NULL)
{
hold = hold->next;
}
hold->next = dark;
dark->prev = hold;
}
return (*head);
}
