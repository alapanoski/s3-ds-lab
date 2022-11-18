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
    char input[MAX_EXPRESSION_LENGTH];
    printf("Enter the expression: ");
    fgets(input, MAX_EXPRESSION_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    int exp[MAX_EXPRESSION_LENGTH], exp_top = -1;
    int op[MAX_EXPRESSION_LENGTH], op_top = -1;
    push(op, MAX_EXPRESSION_LENGTH, &op_top, '#');

    printf("POST for postfix\n");
    printf("PRE for prefix\n");
    char ch[5];
    scanf("%s", ch);

    if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
        strrev(input);

    printf("%s\n", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
            continue;
        if (input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            if (input[i] == '(')
                push(op, MAX_EXPRESSION_LENGTH, &op_top, input[i]);
            if (input[i] == ')')
            {
                while (peek(op, MAX_EXPRESSION_LENGTH, &op_top) != '(')
                    push(exp, MAX_EXPRESSION_LENGTH, &exp_top, pop(op, MAX_EXPRESSION_LENGTH, &op_top));
                pop(op, MAX_EXPRESSION_LENGTH, &op_top);
            }
            if (input[i] == '/')
                push(op, MAX_EXPRESSION_LENGTH, &op_top, input[i]);
            if (input[i] == '*')
            {
                while (peek(op, MAX_EXPRESSION_LENGTH, &op_top) == '/')
                {
                    push(exp, MAX_EXPRESSION_LENGTH, &exp_top, pop(op, MAX_EXPRESSION_LENGTH, &op_top));
                }
                push(op, MAX_EXPRESSION_LENGTH, &op_top, input[i]);
            }
            if (input[i] == '+')
            {
                while (peek(op, MAX_EXPRESSION_LENGTH, &op_top) == '/' || peek(op, MAX_EXPRESSION_LENGTH, &op_top) == '*')
                {
                    push(exp, MAX_EXPRESSION_LENGTH, &exp_top, pop(op, MAX_EXPRESSION_LENGTH, &op_top));
                }
                push(op, MAX_EXPRESSION_LENGTH, &op_top, input[i]);
            }
            if (input[i] == '-')
            {
                while (peek(op, MAX_EXPRESSION_LENGTH, &op_top) == '/' || peek(op, MAX_EXPRESSION_LENGTH, &op_top) == '*' || peek(op, MAX_EXPRESSION_LENGTH, &op_top) == '+')
                {
                    push(exp, MAX_EXPRESSION_LENGTH, &exp_top, pop(op, MAX_EXPRESSION_LENGTH, &op_top));
                }
                push(op, MAX_EXPRESSION_LENGTH, &op_top, input[i]);
            }
        }
        else
        {
            push(exp, MAX_EXPRESSION_LENGTH, &exp_top, input[i]);
        }
    }

    while (peek(op, MAX_EXPRESSION_LENGTH, &op_top) != '#')
    {
        push(exp, MAX_EXPRESSION_LENGTH, &exp_top, pop(op, MAX_EXPRESSION_LENGTH, &op_top));
    }

    if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
        for (int i = exp_top; i >= 0; i--)
            printf("%c ", (char)exp[i]);
    else
        for (int i = 0; i <= exp_top; i++)
            printf("%c ", (char)exp[i]);
    printf("\n");
    return 0;
}
