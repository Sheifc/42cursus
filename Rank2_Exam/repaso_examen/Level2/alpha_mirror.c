#include <unistd.h>
//este ejercicio es mejor hacerlo con contador i
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];
		int i = 0;

		while(s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = ('z' - (s[i] - 'a'));
			else if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = ('Z' - (s[i] - 'A'));
			write(1, s++, 1);
		}	
	}
	write(1, "\n", 1);
}