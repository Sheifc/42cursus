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
	size_t j = 0;

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
	printf("%luResultado\n", ft_strcspn("hola", "comoh"));
	printf("%luResultado\n", strcspn("hola", "comoh"));
} 

/* ./a.out  Devuelve el indice en el que encontró la primera coincidencia de s[i] en reject[j]
0Resultado
0Resultado
 */