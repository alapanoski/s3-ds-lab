#include <stdio.h>
#include <math.h>
#include "stack.c"

#define MAX_BIN_VALUE_SIZE 8
#define MAX_HEX_VALUE_SIZE 8

void decimal_to_binary(int n)
{
	int s[MAX_BIN_VALUE_SIZE];
	int top = -1;
	while(n > 0)
	{
		push(s, MAX_BIN_VALUE_SIZE, &top, n % 2);
		n /= 2;
	}
	
	while(top != -1)
		printf("%d", (int) pop(s, MAX_BIN_VALUE_SIZE, &top));
	printf("\n");
}

void decimal_to_hex(int n)	
{
	int s[MAX_HEX_VALUE_SIZE];
	int top = -1;
	while(n > 0)
	{
		push(s, MAX_HEX_VALUE_SIZE, &top, n % 16);
		n /= 16;
	}
	
	while(top != -1)
	{
		if (peek(s, MAX_HEX_VALUE_SIZE, &top) <= 9)
        {
            printf("%d ", pop(s, MAX_HEX_VALUE_SIZE, &top));
        }
        else
        {
            printf("%c ", (pop(s, MAX_HEX_VALUE_SIZE, &top) + 65 - 9 - 1));
        }
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("Binary value of %d is 0b", n);
	decimal_to_binary(n);
	printf("Hex value of %d is 0x", n);
	decimal_to_hex(n);
	return 1;
}
