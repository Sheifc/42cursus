/* Subject:
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

void expand_str (char *str)
{
	int i = 0;
    
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			write(1,&str[i],1);
			i++;
		}
		while(str[i] == ' ' || str[i] == '\t')
			i++;
		if(str[i] != '\0')
			write(1,"   ",3);
	}

}

int main (int argc, char **argv)
{
	if(argc == 2)
		expand_str(argv[1]);
	write(1,"\n",1);
}



/* void expand_str(char *s)
{
    int i = 0;
    int n = 0;  // Se utilizará para marcar si un espacio necesita ser impreso

    while (s[i]) 
	{
        if (s[i] == ' ' || s[i] == '\t') 
		{
            if (n == 1) // Si ya hemos empezado a imprimir caracteres no espaciados
                n = 2;  // Marcar que un espacio necesita ser impreso antes del próximo carácter no espaciado
        } 
		else // Si es un carácter imprimible
		{  
            if (n == 2)  // Si se marcó que se necesita imprimir un espacio
                write(1, "   ", 3);
            write(1, &s[i], 1);  // Imprimir el carácter no espaciado
            n = 1;  // Marcar que hemos empezado a imprimir caracteres no espaciados
        }
        i++;
    }
}

int main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
} */
