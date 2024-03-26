/* Subject:
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2); */

#include <unistd.h>

char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
}

/* To test:
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s2 = "Hola"; 
	char s1[5];
	char *dest = ft_strcpy(s1, s2);
	char *s4 = "Hola"; 
	char s3[5];
	char *dest2 = strcpy(s3, s4);
	printf("%s\n", dest);
	printf("%s", dest2);
} */