/* Subject:
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject); */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	int j = 0;

	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])	
				return(i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(void)
{
	char *s = "hola";
	char *reject = "ajklm";
	printf("%lu\n", strcspn(s, reject));
	printf("%lu", ft_strcspn(s, reject));
	return (0);
}

/* ./a.out  It returns the index of the first coincidence found of s[i] in reject[j]
0Resultado
0Resultado
 */