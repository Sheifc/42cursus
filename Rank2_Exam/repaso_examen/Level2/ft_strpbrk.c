#include <stdlib.h>

char *ft_strpbrk(const char *s1, const char *s2) //tener en cuenta q son const
{
	int i = 0;
	int j = 0;
	char *aux = (char*)s1; // por eso lo del casteo 

	if(!s1 || !s2)
		return(NULL);
	while (aux[i])
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