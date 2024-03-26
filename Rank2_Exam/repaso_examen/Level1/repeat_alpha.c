#include <unistd.h>

void ft_print(char c, int n)
{
	while(n)
	{
		write(1, &c, 1);
		n--;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];

		if(*s >= 'a' && *s <= 'z')
			ft_print(*s, *s - 'a' + 1);
		else if (*s >= 'A' && *s <= 'Z')
			ft_print(*s, *s - 'A' + 1);
		write(1, s, 1);
		s++;
	}
	write(1,"\n",1);
}