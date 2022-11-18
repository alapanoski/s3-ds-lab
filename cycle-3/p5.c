#include <stdio.h>
#include <ctype.h>
#include "stack.c"

#define MAX_STRING_SIZE 20

int is_palindrome(char str[MAX_STRING_SIZE])
{

	int s[MAX_STRING_SIZE];
	int top = -1;
	char rev_str[MAX_STRING_SIZE];
	for(int i = 0; str[i] != '\0'; i++)
		push(s, MAX_STRING_SIZE, &top, (int) str[i]);
	for(int i = 0; str[i] != '\0'; i++)
		rev_str[i] = (char) pop(s, MAX_STRING_SIZE, &top);
	
	for(int i = 0; str[i] != '\0'; i++)
		if(tolower(str[i]) != tolower(rev_str[i]))
			return 0;
		
	return 1;
}

int main()
{
	char str[MAX_STRING_SIZE];

	printf("Enter a string: ");
	scanf("%s", str);
	
	if(is_palindrome(str))
		printf("%s is palindrome\n", str);
	else
		printf("%s is not palindrome\n", str);
		
	return 1;
}
