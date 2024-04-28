/* Subject:
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first 
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $ */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (argv[2][j])
		j++;
	while (argv[3][k])
		k++;
	if (argc == 4 && j == 1 && k == 1)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == *argv[2])
				argv[1][i] = *argv[3];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

// Otro modo: pasa el grademe también

#include <unistd.h>

int ft_strlen(char *s)
{
	int j = 0;
	while(s[j])
		j++;
	return(j);
}

void search_replace(char *s1,char *s2,char *s3)
{
	int i = 0;
	if ((ft_strlen(s2) == 1) && (ft_strlen(s3) == 1))
	{
		while (s1[i])
		{
			if (s1[i] == s2[0])
				s1[i] = s3[0];
			write(1, &s1[i], 1);
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 4)
		search_replace(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
}

// Otro modo:

void search_replace(char *s1, char *s2, char *s3)
{
	int i = 0;
	
	while (s1[i])
	{
		if (s1[i] == s2[0])
			s1[i] = s3[0];
		write(1, &s1[i], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 4 && ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		search_replace(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
}
