#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char *s = argv[1];

		while (s[i])
			i++;
		i--;
		while (i >= 0)
		{
			write(1, &s[i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
}