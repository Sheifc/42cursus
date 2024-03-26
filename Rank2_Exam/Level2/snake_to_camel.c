/* Subject:
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./camel_to_snake "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./camel_to_snake "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

// pasa el grademe:

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
// otro modo:
/* void snake_to_camel(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			str[i] -= 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	write(1, "\n", 1);
} */
