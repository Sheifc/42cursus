#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];

		while (*s)
		{
			if (*s >= 'a' && *s <= 'm' || *s >= 'A' && *s <= 'M')
				*s += 13;
			else if (*s >= 'n' && *s <= 'z' || *s >= 'N' && *s <= 'Z')
				*s -= 13;
			else
				*s = *s;
			write(1, s, 1);
			s++;
		}
	}
	write(1, "\n", 1);
}