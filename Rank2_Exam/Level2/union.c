/* Subject:
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void ft_union(char *s1, char*s2)
{
	char tab[256] = {0};
	int i = 0;

	while (s1[i])
		tab[(int)s1[i++]] = 1;
	i = 0;
	while (s2[i])
		tab[(int)s2[i++]] = 1; 
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1) 
		{
			write(1, &s1[i], 1);
			tab[(int)s1[i]] = 2;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (tab[(int)s2[i]] == 1) 
		{
			write(1, &s2[i], 1);
			tab[(int)s2[i]] = 2;
		}
		i++;
	}
}

// To test:
int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

// Another way: 

int ft_check(char c,char *str,int index)
{
    int i;
    i = 0;
    while(i < index)
    {
        if(str[i] == c)
            return (0);
        i++;
    }
    return(1);
}
int main(int argc,char **argv)
{
    int i = 0;
    int j = 0;
    char *str1 = argv[1];
    char *str2 = argv[2];
    if(argc != 3)
        return(write(1,"\n",1));
    while(str2[i])
    {
        while(str1[j] == str2[i])
            {
                if(ft_check(str1[j],str1,j) == 1)
                    write(1,&str1[j],1);
                j++;
            }
        i++;
    }
    write(1,"\n",1);
	return (0);
}
