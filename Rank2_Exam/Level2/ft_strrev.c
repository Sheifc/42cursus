/* Subject:
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char aux;

	while(str[i])
		i++;
	i = i - 1; // las posiciones empiezan en 0,1,2,3,4 "hola\0" por eso i vale 4 y hay q eliminar 1 para entrar en la ultima posicion saltando el nulo
	while(j < i)
	{
		aux = str[i];
		str[i] = str[j]; 
		str[j] = aux;
		j++;
		i--;
	}
	return(str);
}

int main()
{
	char str[5] = "hola";
	printf("%s", ft_strrev(str));
}
