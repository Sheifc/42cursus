#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];

		while (*s)
		{
			if (*s >= 'a' && *s <= 'y' || *s >= 'A' && *s <= 'Y')
				*s += 1;
			else if (*s == 'z' || *s == 'Z')
				*s -= 25;
			else 
				*s = *s; 
			write(1, s, 1);
			s++;
		}
	}
	write(1, "\n", 1);
}