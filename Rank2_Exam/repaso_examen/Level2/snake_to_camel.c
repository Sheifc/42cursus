#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char *s = argv[1];

		while (s[i])
		{
			while (s[i] && s[i] != '_')
				write(1, &s[i++], 1);
			if (s[i] == '_')
			{
				i++;
				s[i] -= 32;
			}
		}
	}
	write(1, "\n", 1);
}