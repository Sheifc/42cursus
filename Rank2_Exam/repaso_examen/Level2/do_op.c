#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* int main(int argc, char **argv)
{
	if (argc == 4)
	{ 
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		else if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		else if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		else if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		else if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	write(1, "\n", 1);
} */

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '+') // si no pongo [0] me dice que do_op.c:39:15: error: comparison between pointer and integer ('char *' and 'int') [-Werror,-Wpointer-integer-compare]
			printf("%d", (atoi(argv[1])) + (atoi(argv[3])));
		if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1])) - (atoi(argv[3])));
		if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1])) * (atoi(argv[3])));
		if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1])) / (atoi(argv[3])));
		if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1])) % (atoi(argv[3])));
	}
	printf("\n");
	return (0);
}