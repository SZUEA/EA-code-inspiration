#include <stdio.h>
int main()
{
	char c;
	int letter = 0, number = 0, space = 0, other = 0;
	printf("Please input a line of characters:\n");
	while ((c = getchar()) != '\n')
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			letter++;
		else if (c >= '0' && c <= '9')
			number++;
		else if (c == ' ')
			space++;
		else
			other++;
	printf("Letters:%d, Digits:%d, White Spaces:%d, Others:%d", letter, number, space, other);
	return 0;
}