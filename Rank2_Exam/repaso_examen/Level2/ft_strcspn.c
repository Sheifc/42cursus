#include <string.h>
#include <stdio.h>

//retorna el primer indice de s que encuentra en reject
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	int j = 0;

	while(s[i])
	{
		j = 0;
		while(reject[j])
		{  
			if (s[i] == reject[j])
				return(i);
			j++;
	    }
		i++;
	}
	return (0);
}

int main(void)
{
	char *s = "hola";
	char *reject = "ajklm";
	printf("%lu\n", strcspn(s, reject));
	printf("%lu", ft_strcspn(s, reject));
}