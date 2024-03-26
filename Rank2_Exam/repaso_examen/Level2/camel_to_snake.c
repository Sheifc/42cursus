#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{    
		char *s = argv[1];
		int i = 0;

		while(s[i])
		{
			while (s[i] >= 'a' && s[i] <= 'z')
				write(1, &s[i++], 1);
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				write(1, "_", 1);
				s[i] += 32;
				write(1, &s[i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}