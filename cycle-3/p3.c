#include <stdio.h>
#include <string.h>
#include "stack.c"

#define STACK_SIZE 10
#define MAX_INPUT_SIZE 20

int min_s[STACK_SIZE];
int min_s_top = -1;

void push_to_stack(int stack[], int size, int *top, int item)
{
    if (*top == -1)
    {
        push(stack, size, top, item);
        push(min_s, size, &min_s_top, item);
        return;
    }
    if (item <= peek(min_s, size, &min_s_top))
    {
        push(stack, size, top, item);
        push(min_s, size, &min_s_top, item);
    } 
    else
        push(stack, size, top, item);
}

int pop_from_stack(int stack[], int size, int *top)
{
    if ((*top) < 0)
    {
        printf("Stack underflow\n");
        return ++(*top);
    }
    if (min_s_top != -1 && peek(min_s, size, &min_s_top) == peek(stack, size, top))
    {
        pop(min_s, size, &min_s_top);
        return pop(stack, size, top);
    }
    else
    {
        return pop(stack, size, top);
    }
    return stack[(*top)--];
}

int get_min()
{
    return min_s[min_s_top];
}

int main()
{
    int s[STACK_SIZE];
    int top = -1;

    printf("Avialable operations are\n");
    printf("PUSH <value>\n");
    printf("POP\n");
    printf("PEEK\n");
    printf("MIN\n");
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
            push_to_stack(s, STACK_SIZE, &top, value);
            printf("-------------------------\n");
            print_stack(s, STACK_SIZE, &top);
        }
        // Pop
        else if (ch[0] == 'P' && ch[1] == 'O' && ch[2] == 'P')
        {
            int value = pop_from_stack(s, STACK_SIZE, &top);
            print_stack(s, STACK_SIZE, &top);
            printf("-------------------------\n");
            printf("Popped value: %d\n", value);
        }
        // Peek
        else if (ch[0] == 'P' && ch[1] == 'E' && ch[2] == 'E' && ch[3] == 'K')
        {
            int value = peek(s, STACK_SIZE, &top);
            print_stack(s, STACK_SIZE, &top);
            printf("-------------------------\n");
            printf("Peeked value: %d\n", value);
        }
        // Getting minimum value
        else if (ch[0] == 'M' && ch[1] == 'I' && ch[2] == 'N')
        {
        	printf("Minimum element is %d\n", get_min());
        }
        else
        {
            printf("-------------------------\n");
            print_stack(s, STACK_SIZE, &top);
            printf("Invalid operation\n");
        }
    } while (strcmp(ch, "EXIT\n") != 0);

    for (int i = 0; i <= top; i++)
        printf("%d ", s[i]);
    printf("\n");
    for (int i = 0; i <= min_s_top; i++)
        printf("%d ", min_s[i]);
    printf("\n");

    printf("%d", get_min());
    printf("\n");
}
