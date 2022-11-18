void push(int stack[], int size, int *top, int item)
{
    if ((*top) == size)
    {
        printf("Error: stack overflow\n");
        return;
    }
    stack[++(*top)] = item;
}

int pop(int stack[], int size, int *top)
{
    if ((*top) < 0)
    {
        printf("Error: stack underflow\n");
        return *top;
    }
    return stack[(*top)--];
}

int peek(int stack[], int size, int *top)
{
    if ((*top) < 0)
    {
        printf("Error: stack underflow\n");
        return *top;
    }
    return stack[(*top)];
}

int is_empty(int stack[], int size, int *top)
{
    if (*top == -1)
        return 1;
    return 0;
}

int is_full(int stack[], int size, int *top)
{
    if (*top == size - 1)
        return 1;
    return 0;
}

void print_stack(int stack[], int size, int *top)
{
    if (is_empty(stack, size, top))
    {
        printf("Stack is empty\n");
        return;
    }
    // Formatting
    for (int i = 0; i <= *top; i++)
    {
        printf("| %d ", stack[i]);
    }
    printf("\n");
}