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

char    *ft_strdup(char *src)
{
	char *copy;
	int i = 0;

	while(src[i])
		i++;
	copy = malloc(sizeof(char) * i + 1); // 1 por el nulo
	if(!copy)
		return(NULL);
	i = 0;
	while(src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int main(void)
{
	printf("%s", ft_strdup("1324"));
	printf("%s", strdup("1324"));
}