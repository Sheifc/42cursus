/* 
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e // si
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y" // si
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e //si
$
$>
*/

#include <unistd.h>

void rostring(char *str)
{
	int i = 0;
	int end = 0;
	int start = 0;

	while (str[i] == 32 || str[i] == '\t')
		i++;
	start = i;
	while (str[i] && (str[i] != 32 && str[i] != '\t'))
		i++;
	end = i;
	while (str[i] == 32 || str[i] == '\t')
		i++;
 	while (str[i])
	{
		while (str[i] && str[i] != 32 && str[i] != '\t')
		{
			write(1, &str[i], 1);
			i++;
		}
		while (str[i] == 32 || str[i] == '\t')
			i++;
		write(1," ",1);
	}
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int main (int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	retutn (0);
}
