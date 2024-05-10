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
	while(n)
	{
		write(1, &c, 1);
		n--;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];

		if(*s >= 'a' && *s <= 'z')
			ft_print(*s, *s - 'a' + 1);
		else if (*s >= 'A' && *s <= 'Z')
			ft_print(*s, *s - 'A' + 1);
		write(1, s, 1);
		s++;
	}
	write(1,"\n",1);
	return (0);
}
