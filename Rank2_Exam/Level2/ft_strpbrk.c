/* Subject:
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2); */

#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;
	char *aux = (char*) s1; 

	while(s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if (aux[i] == s2[j])
				return(&aux[i]);
			j++;
		}
		i++;
	}
	return(NULL);
}

int main(void)
{
	printf("%s\n", ft_strpbrk("holacomoestas", "estas"));
	printf("%s", strpbrk("holacomoestas", "estas"));
	printf("%s\n", ft_strpbrk("", "estas"));
	printf("%s", strpbrk("", "estas"));
	printf("%s\n", ft_strpbrk("hola", ""));
	printf("%s", strpbrk("hola", ""));
}