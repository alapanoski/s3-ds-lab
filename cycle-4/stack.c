#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *new_stack()
{
    return malloc(sizeof(struct node));
}

void print(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

void push(struct node **head, int item)
{
    if (*head == NULL)
    {
        struct node *n = malloc(sizeof(struct node));
        n->data = item;
        n->next = NULL;
        *head = n;
    }
    else
    {
        struct node *n = malloc(sizeof(struct node));
        n->data = item;
        n->next = *head;
        *head = n;
    }
}

int pop(struct node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

int peek(struct node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return (*head)->data;
}