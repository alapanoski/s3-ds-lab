#include <stdio.h>
#include <string.h>
#include "stack.c"

#define MAX_EXPRESSION_LENGTH 50

void strrev(char *str)
{
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        char temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

int main()
{
    char exp[MAX_EXPRESSION_LENGTH];
    printf("Enter the expression: ");
    fgets(exp, MAX_EXPRESSION_LENGTH, stdin);
    exp[strcspn(exp, "\n")] = 0;

    printf("POST for postfix\n");
    printf("PRE for prefix\n");
    char ch[5];
    scanf("%s", ch);

    if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
        strrev(exp);

    printf("%s\n", exp);

    int ans = 0;
    int stack[MAX_EXPRESSION_LENGTH], top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (exp[i] == ' ')
            continue;

        if (exp[i] == '/')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
                ans = x / y;
            else
                ans = y / x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else if (exp[i] == '*')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            ans = y * x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else if (exp[i] == '+')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            ans = y + x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else if (exp[i] == '-')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
                ans = x - y;
            else
                ans = y - x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else
            push(stack, MAX_EXPRESSION_LENGTH, &top, exp[i] - '0');
    }

    printf("Ans = %d\n", ans);

    return 0;
}
