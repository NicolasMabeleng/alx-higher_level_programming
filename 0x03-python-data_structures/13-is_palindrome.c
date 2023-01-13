#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head)
{
    listint_t *temp = *head;
    int len = 0, i;
    int a[4096];

    if (*head == NULL)
        return (1);

    while (temp != NULL)
    {
        a[len] = temp->n;
        temp = temp->next;
        len++;
    }

    for (i = 0; i < len / 2; i++)
    {
        if (a[i] != a[len - i - 1])
            return (0);
    }
    return (1);
}

