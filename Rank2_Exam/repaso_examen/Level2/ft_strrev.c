#include <stdio.h>

char *ft_strrev(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	i--;
	int j = 0;
	char aux;
	while(j < i) //en esto he fallado, he puesto i >= 0 y asi no sale claro
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i--;
		j++;
	}
	return(str);
}

int main(void)
{
	char s[5] = "hola";
	char *rev = ft_strrev(s);
	printf("%s", rev);
}