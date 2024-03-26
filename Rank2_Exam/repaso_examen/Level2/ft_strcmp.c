#include <string.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2); //asi solo compara la primera letra de cada string, hay q iterar
}

int main(void)
{
	char *s1 = "a";
	char *s2 = "a";
	printf("%d\n", ft_strcmp(s1, s2));
	char *s3 = "a";
	char *s4 = "a";
	printf("%d", strcmp(s3, s4));
}