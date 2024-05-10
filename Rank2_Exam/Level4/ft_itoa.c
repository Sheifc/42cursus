/* Subject:
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	long n = (long)nbr;
	int len = 0;

	if (n <= 0)
		len++;
	long n_copy = n;
	while (n_copy)
	{
		n_copy /= 10;
		len++;
	}
	char *s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return NULL;
	s[len] = '\0';
	len -= 1;
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (s);
}

// To test:
int main(void)
{
	int n = -256789;
	char *str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	return (0);
}
