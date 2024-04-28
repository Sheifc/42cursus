/* Subject:
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$ */

// Debe mostrar, sin repetir caracteres, 
// todos los caracteres de s1 que aparecen en ambas cadenas.

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i = 0;
	int	tab[256] = {0};

	while (s2[i])
		tab[(int)s2[i++]] = 1; // asignamos a los elementos de s2 el numero 1
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1) // si los elementos de s1 son 1 significa q es igual a s2
		{
			write(1, &s1[i], 1);
			tab[(int)s1[i]] = 2; // para q no lo vuelva a imprimir, le asignamos el valor 2
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

//ref: https://www.youtube.com/watch?app=desktop&v=NTyBvR8lJU8


// Otro modo: 

/* #include <unistd.h>
int ft_check(char c,char *str,int index)
{
    int i = 0;

    while (i < index)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return(1);
}
int main (int argc,char **argv)
{
    int i = 0;
    int j = 0;
    char *str1 = argv[1];
    char *str2 = argv[2];

    if (argc == 3)
    {
        while (str2[i])
        {
            while (str1[j] == str2[i])
                {
                    if (ft_check (str1[j],str1,j) == 1)
                        write (1,&str1[j],1);
                    j++;
                }
            i++;
        }
    }
    write(1,"\n",1);
} */
