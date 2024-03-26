#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];

		while (*s == 32 || *s == 9)
			s++;
		while ((*s != 32 && *s != 9) && *s) // se me ha olvidado poner *s
			write(1, s++, 1);
	}
	write(1, "\n", 1);
}