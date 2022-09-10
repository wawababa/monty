#include "monty.h"
/**
 *pop - remove heads of list
 *@head: head of the list
 *@val: line number
 *Return: nothing
 */
void pop(stack_t **head, unsigned int val)
{
stack_t *hold;
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", val);
fclose(datas.file);
exit(EXIT_FAILURE);
}
hold = *head;
*head = (*head)->next;
free(hold);
}
/**
 *swap - swap staacks
 *@head: head of the list
 *@val: number of line
 *Return: Nothing
 */
void swap(stack_t **head, unsigned int val)
{
int hold;
if (!(*head) || !((*head)->next) || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", val);
free_memo(*head);
fclose(datas.file);
exit(EXIT_FAILURE);
}
hold = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = hold;
}
/**
 *addstack - add two stack values
 *@head: head of stack
 *@val: number of line
 *Return: nothing
 */
void addstack(stack_t **head, unsigned int val)
{
int num;
if (!(*head) || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", val);
free_memo(*head);
fclose(datas.file);
exit(EXIT_FAILURE);
}
num = (*head)->n + (*head)->next->n;
pop(head, val);
(*head)->n = num;
}
/**
 *nop - do nothing
 *@head: head of the list
 *@val: number of line
 *Return: nothing
 */
void nop(__attribute__((unused)) stack_t **head, unsigned int val)
{
(void) val;
}
/**
 *sub - add two stack values
 *@head: head of stack
 *@val: number of line
 *Return: nothing
 */
void sub(stack_t **head, unsigned int val)
{
int num;
if (!(*head) || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", val);
free_memo(*head);
fclose(datas.file);
exit(EXIT_FAILURE);
}
num = (*head)->next->n - (*head)->n;
pop(head, val);
(*head)->n = num;
}
