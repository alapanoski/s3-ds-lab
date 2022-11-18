#include <stdio.h>
#include <string.h>
#include "stack.c"

#define MAX_INPUT_SIZE 25

int main()
{
    int MAX_STACK_SIZE;
    printf("Enter stack size: ");
    scanf("%d", &MAX_STACK_SIZE);
    MAX_STACK_SIZE--;

    int s[MAX_STACK_SIZE];
    int top = -1;

    printf("Avialable operations are\n");
    printf("PUSH <value>\n");
    printf("POP\n");
    printf("PEEK\n");
    printf("IS_EMPTY\n");
    printf("IS_FULL\n");
    printf("EXIT\n");
    char ch[MAX_INPUT_SIZE];
    do
    {
        fgets(ch, MAX_INPUT_SIZE, stdin);

        // Push
        if (ch[0] == 'P' && ch[1] == 'U' && ch[2] == 'S' && ch[3] == 'H')
        {
            int value = 0;
            for (int i = 5; i < strlen(ch) - 1; i++)
                value = value * 10 + (ch[i] - '0');
            push(s, MAX_STACK_SIZE, &top, value);
            printf("-------------------------\n");
            print_stack(s, MAX_STACK_SIZE, &top);
        }
        // Pop
        else if (ch[0] == 'P' && ch[1] == 'O' && ch[2] == 'P')
        {
            int value = pop(s, MAX_STACK_SIZE, &top);
            print_stack(s, MAX_STACK_SIZE, &top);
            printf("-------------------------\n");
            printf("Popped value: %d\n", value);
        }
        // Peek
        else if (ch[0] == 'P' && ch[1] == 'E' && ch[2] == 'E' && ch[3] == 'K')
        {
            int value = peek(s, MAX_STACK_SIZE, &top);
            print_stack(s, MAX_STACK_SIZE, &top);
            printf("-------------------------\n");
            printf("Peeked value: %d\n", value);
        }
        else
        {
            printf("-------------------------\n");
            print_stack(s, MAX_STACK_SIZE, &top);
            printf("Invalid operation\n");
        }
    } while (strcmp(ch, "EXIT\n") != 0);

    return 1;
}
