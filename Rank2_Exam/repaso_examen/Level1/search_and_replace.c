#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;

	while(s[i])
		i++;
	return (i);
}

void replace(char *s1, char *s2, char *s3)
{
	int i = 0;

	while (s1[i])
	{ 
		if (s1[i] == s2[0])
			s1[i] = s3[0];
		write(1, &s1[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4 && (ft_strlen(argv[2]) == 1) && (ft_strlen(argv[3]) == 1))
	{
		replace(argv[1], argv[2], argv[3]);
	}
	write(1, "\n", 1);
}