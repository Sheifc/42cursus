/* Subject: 
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src); */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;

	while(s[i])
		i++;
	return (i);
}
char *ft_strdup(char *src)
{
	char *dest = malloc(sizeof(char)* (ft_strlen(src) + 1));
	if (!dest)
		return(NULL);
	int j = 0;

	while(src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\n';
	return (dest);
}

// To test:
int main(void)
{
	printf("%s", ft_strdup("1324"));
	printf("%s", strdup("1324"));
	return (0);
}
