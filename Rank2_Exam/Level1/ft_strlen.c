/* Subject:
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str); */

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

/* To test:
#include <stdio.h>

int main(void)
{
	char *str = "Hola";
	int i = ft_strlen(str);

	printf("%d\n", i);
} */