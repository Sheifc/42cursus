/* Subject:
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$> */

#include <unistd.h>

void ft_print(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

void repeat_alpha(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			ft_print(*str, *str - 'a' + 1); // str = 'a': 97 - 97 + 1 = 1 vez
		else if (*str >= 'A' && *str <= 'Z')
			ft_print(*str, *str - 'A' + 1);
        else
            write(1, str, 1);
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
			repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
