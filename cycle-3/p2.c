#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 25

void push(int s[], int which_stack, int size, int *t_1, int *t_2, int item)
{
    if (*t_1 + 1 == *t_2)
    {
        printf("Stack full\n");
        return;
    }
    switch (which_stack)
    {
    case 1:
        s[++(*t_1)] = item;
        break;
    case 2:
        s[--(*t_2)] = item;
        break;
    }
}

int pop(int s[], int which_stack, int size, int *t_1, int *t_2)
{
    switch (which_stack)
    {
    case 1:
        if (*t_1 == -1)
        {
            printf("Stack underflow\n");
            return -1;
        }
        else
            return s[(*t_1)--];
        break;
    case 2:
        if (*t_2 == size)
        {
            printf("Stack underflow\n");
            return -1;
        }
        else
            return s[(*t_2)++];
        break;
    }
}

int peek(int s[], int which_stack, int size, int *t_1, int *t_2)
{
    switch (which_stack)
    {
    case 1:
        if (*t_1 == -1)
        {
            printf("Stack empty\n");
            return -1;
        }
        else
            return s[(*t_1)];
        break;
    case 2:
        if (*t_2 == size)
        {
            printf("Stack empty\n");
            return -1;
        }
        else
            return s[(*t_2)];
        break;
    }
}

void print_stack(int s[], int which_stack, int size, int *t_1, int *t_2)
{
    switch (which_stack)
    {
    case 1:
        if (*t_1 == -1)
        {
            printf("Stack empty\n");
        }
        else
        {
            printf("Stack 1: ");
            for (int i = 0; i <= *t_1; i++)
                printf("%d ", s[i]);
            printf("\n");
        }
        break;
    case 2:
        if (*t_2 == size)
        {
            printf("Stack empty\n");
        }
        else
        {
            printf("Stack 2: ");
            for (int i = size - 1; i >= *t_2; i--)
                printf("%d ", s[i]);
            printf("\n");
        }
        break;
    }
}

void print_both_stacks(int s[], int size, int *t_1, int *t_2)
{
    if (*t_1 != -1)
    {
        printf("Stack 1: ");
        for (int i = 0; i <= *t_1; i++)
            printf("%d ", s[i]);
        printf("\n");
    }
    if (*t_2 != size)
    {
        printf("Stack 2: ");
        for (int i = size - 1; i >= *t_2; i--)
            printf("%d ", s[i]);
        printf("\n");
    }
}

int main()
{
    int MAX_STACK_SIZE;
    printf("Enter stack size: ");
    scanf("%d", &MAX_STACK_SIZE);

    int s[MAX_STACK_SIZE];
    int t_1 = -1, t_2 = MAX_STACK_SIZE;

    printf("Avialable operations are\n");
    printf("PUSH <which stack> <value>\n");
    printf("POP <which stack>\n");
    printf("PEEK\n");
    printf("EXIT\n");
    char ch[MAX_INPUT_SIZE];
    do
    {
        fgets(ch, MAX_INPUT_SIZE, stdin);

        // Push
        if (ch[0] == 'P' && ch[1] == 'U' && ch[2] == 'S' && ch[3] == 'H')
        {
            int value = 0;
            int which_stack = 0;
            which_stack = ch[5] - '0';
            for (int i = 7; i < strlen(ch) - 1; i++)
                value = value * 10 + (ch[i] - '0');
            push(s, which_stack, MAX_STACK_SIZE, &t_1, &t_2, value);
            printf("-------------------------\n");
            print_both_stacks(s, MAX_STACK_SIZE, &t_1, &t_2);
        }
        // Pop
        else if (ch[0] == 'P' && ch[1] == 'O' && ch[2] == 'P')
        {
            int which_stack = 0;
            which_stack = ch[4] - '0';
;
		printf("%d\n", which_stack);
            int value = pop(s, which_stack, MAX_STACK_SIZE, &t_1, &t_2);
            printf("-------------------------\n");
            print_both_stacks(s, MAX_STACK_SIZE, &t_1, &t_2);
            printf("Popped value: %d\n", value);
        }
        // Peek
        else if (ch[0] == 'P' && ch[1] == 'E' && ch[2] == 'E' && ch[3] == 'K')
        {
            int which_stack = 0;
            which_stack = ch[5] - '0';
            int value = peek(s, which_stack, MAX_STACK_SIZE, &t_1, &t_2);
            printf("-------------------------\n");
            print_both_stacks(s, MAX_STACK_SIZE, &t_1, &t_2);
            printf("Peeked value: %d\n", value);
        }
        else
        {
            printf("-------------------------\n");
            print_both_stacks(s, MAX_STACK_SIZE, &t_1, &t_2);
            printf("Invalid operation\n");
        }
    } while (strcmp(ch, "EXIT\n") != 0);

    for (int i = 0; i < MAX_STACK_SIZE; i++)
        printf("%d ", s[i]);
    printf("\n");
}
