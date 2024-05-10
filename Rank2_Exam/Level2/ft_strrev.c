/* Subject:
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char aux;

	while (str[i])
		i++;
	i--;
	while (j < i)
	{
		aux = str[i];
		str[i] = str[j]; 
		str[j] = aux;
		i--;
		j++;
	}
	return (str);
}

// To test:
int main()
{
	char str[5] = "hola";
	printf("%s", ft_strrev(str));
	return (0);
}
