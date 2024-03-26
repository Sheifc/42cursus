#include <unistd.h>
#include <stdio.h>
#include <string.h>

char ft_strcpy(char *s1, char *s2)
{
	while(*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return(*s1);
}

int main(void)
{
	char s1[20];
	char *s2 = "hola como estas\n";
	ft_strcpy(s1, s2);
	printf("%s", s1);
	char s3[20];
	char *s4 = "hola como estas";
	strcpy(s3, s4);
	printf("%s", s3);
}