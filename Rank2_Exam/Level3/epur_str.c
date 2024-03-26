/* Subject:
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$> */

#include <unistd.h>

void epur_str (char *str)
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
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			write(1," ",1);
	}

}

int main (int argc, char **argv)
{
	if(argc == 2)
		epur_str(argv[1]);
	write(1,"\n",1);
}
/* void epur_str(char *s)
{
	int i = 0;

	if (s[i] == 32 || s[i] == '\t')
		i++;
	while (s[i] && (s[i] >= 32 && s[i] <= 126))
	{
		if (s[i] >= 33 && s[i] <= 126)
			write(1, &s[i], 1); // no se pone &s xq sino resulta en la impresion de la direccion de memoria 
		if (s[i] == 32)
			write(1, " ", 1);
		i++;
	}
} */

/* void epur_str(char *s)
{
	int i = 0;
	int n;

	while (s[i] == 32 || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == 32 || s[i] == '\t')
			n = 1;
		else if (!(s[i] == 32 || s[i] == '\t'))
		{
			if (n) // si n es verdadero osea 1
			{
				write(1, " ", 1);
				n = 0;
			}
			write(1, &s[i], 1);
		}
		i++;
	}
} */
/*
#include <unistd.h>

 void epur_str(char *s)
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
                write(1, " ", 1);
            write(1, &s[i], 1);  // Imprimir el carácter no espaciado
            n = 1;  // Marcar que hemos empezado a imprimir caracteres no espaciados
        }
        i++;
    }
} */

/* 
En este código:

n se pone a 1 después de imprimir el primer carácter no espaciado.
n se pone a 2 si se encuentra un espacio después de imprimir un carácter no espaciado.
Un espacio solo se imprime si n es 2, lo cual solo ocurre si ya se ha impreso un carácter no espaciado. */

/* int main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
} */
