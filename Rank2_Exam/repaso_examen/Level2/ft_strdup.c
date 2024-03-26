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