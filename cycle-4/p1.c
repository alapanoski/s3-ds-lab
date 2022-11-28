#include <stdio.h>
#include <string.h>
#include "stack.c"

#define MAX_INPUT_SIZE 10

int main()
{
    struct node *stack = new_stack();
    stack->next = NULL;
    pop(&stack);
    char ch[MAX_INPUT_SIZE];
    printf("Avialable operations are\n");
    printf("PUSH <value>\n");
    printf("POP\n");
    printf("PEEK\n");
    printf("EXIT\n");
    do
    {
        fgets(ch, MAX_INPUT_SIZE, stdin);
        // Push
        if (ch[0] == 'P' && ch[1] == 'U' && ch[2] == 'S' && ch[3] == 'H')
        {
            int value = 0;
            for (int i = 5; i < strlen(ch) - 1; i++)
                value = value * 10 + (ch[i] - '0');
            push(&stack, value);
            printf("-------------------------\n");
            print(stack);
        }
        // Pop
        else if (ch[0] == 'P' && ch[1] == 'O' && ch[2] == 'P')
        {
            int value = pop(&stack);
            print(stack);
            printf("-------------------------\n");
            if (value != -1)
                printf("Popped value: %d\n", value);
        }
        // Peek
        else if (ch[0] == 'P' && ch[1] == 'E' && ch[2] == 'E' && ch[3] == 'K')
        {
            int value = peek(&stack);
            print(stack);
            printf("-------------------------\n");
            if (value != -1)
                printf("Peeked value: %d\n", value);
        }
        else
        {
            printf("-------------------------\n");
            print(stack);
            printf("Invalid operation\n");
        }
    } while (strcmp(ch, "EXIT\n") != 0);
    
    return 0;
}