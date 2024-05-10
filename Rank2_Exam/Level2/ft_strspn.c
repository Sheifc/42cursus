/* Subject:
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept); */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i])
	{
		if (ft_strchr(accept, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

// To test:
int main (void)
{
	char *s = "hola";
	char *s2 = "ohpa";

	printf("%lu\n", ft_strspn(s, s2));
	printf("%lu", strspn(s, s2));
	return (0);
}

/* ./a.out        
2
2%                         
*/
