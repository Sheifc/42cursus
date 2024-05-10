/* Subject:
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2); */

#include <unistd.h>

char ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (*s1);
}

// Another way:

char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/* To test:
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[20];
	char *s2 = "hello how are you\n";
	ft_strcpy(s1, s2);
	printf("%s", s1);
	char s3[20];
	char *s4 = "hello how are you";
	strcpy(s3, s4);
	printf("%s", s3);
	return (0);
} */