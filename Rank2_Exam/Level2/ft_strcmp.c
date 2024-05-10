/* Subject:
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// To test:
int main(void)
{
	char *s1 = "a";
	char *s2 = "a";
	printf("%d\n", ft_strcmp(s1, s2));
	char *s3 = "a";
	char *s4 = "a";
	printf("%d", strcmp(s3, s4));
	return (0);
}
