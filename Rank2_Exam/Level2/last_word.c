/* Substartect:
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$> */

/* 
./a.out "Manger pour vivre "
        🗝 EXPECTED OUTPUT:
vivre$
 */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];
		int i = 0;
		int start = 0;
		int end = 0;

		while(s[i])
			i++;
		i--;
		while(s[i] == 32 || s[i] == 9)
			i--;
		end = i + 1;
		while(i >= 0 && s[i] != 32 && s[i] != 9)
			i--;
		start = i + 1;
		while(start < end)
			write(1, &s[start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
