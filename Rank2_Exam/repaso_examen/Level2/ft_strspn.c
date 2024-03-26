#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *accept, char c)
{
	while(*accept)
	{
		if (*accept == c)
			return ((char*)accept);
		accept++;
	}
	return(NULL);
}

size_t ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while(s[i])
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		i++;
	}
	return(i);
}

int main (void)
{
	char *s = "hola";
	char *s2 = "ohpa";
	printf("%lu\n", ft_strspn(s, s2));
	printf("%lu", strspn(s, s2));
}