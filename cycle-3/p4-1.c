#include <stdio.h>
#include "stack.c"

#define STACK_SIZE 10

int aux_s[STACK_SIZE];
int aux_s_t = -1;

void push_to_stack(int stack[], int size, int *top, int item, char sorting)
{
    if (*top == -1)
        push(stack, size, top, item);
    else
    {
		switch(sorting)
		{
		case 'a':
            if (item <= peek(stack, size, top))
            {
                while (item <= peek(stack, size, top))
                {
                    push(aux_s, size, &aux_s_t, pop(stack, size, top));
                    if(*top == -1) break;
                    
                }
                push(stack, size, top, item);
                while (aux_s_t != -1)
                    push(stack, size, top, pop(aux_s, size, &aux_s_t));
            }
            else
            {
                push(stack, size, top, item);
            }
       	break;
       	case 'd':
            if (item >= peek(stack, size, top))
            {
                while (item >= peek(stack, size, top))
                {
                    push(aux_s, size, &aux_s_t, pop(stack, size, top));
                    if(*top == -1) break;
                    
                }
                push(stack, size, top, item);
                while (aux_s_t != -1)
                    push(stack, size, top, pop(aux_s, size, &aux_s_t));
            }
            else
            {
                push(stack, size, top, item);
            }
        break;
        default:
        	printf("Error: sorting type is not defined\n");
      	}
	}
}

int main()
{
    int s[STACK_SIZE];
    int top = -1;

    char sorting;
    printf("Enter 'a' for ascending and 'd' for descending: ");
    scanf("%c", &sorting);
    printf("Enter 10 elements: ");
   	for(int i = 0; i < STACK_SIZE; i++)
   	{
   		int x;
   		scanf("%d", &x);
   		push_to_stack(s, STACK_SIZE, &top, x, sorting);
	}
    
    for(int i = 0; i <= top; i++)
    	printf("%d ", s[i]);
    printf("\n");
    	
}
