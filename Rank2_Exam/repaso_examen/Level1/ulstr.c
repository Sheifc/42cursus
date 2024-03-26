#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];
		int i = 0;

		while(*s)
		{
			if (*s >= 'a' && *s <= 'z')
				*s -= 32;
			else if (*s >= 'A' && *s <= 'Z')
				*s += 32;
			write(1, s++, 1);
		}
	}
	write(1, "\n", 1);
}