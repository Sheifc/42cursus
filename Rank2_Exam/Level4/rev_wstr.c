/* Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$> */

#include <unistd.h>
#include <stdlib.h>

/* void rev_wstr(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int flag = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		while (str[i] == '\0' || str[i] == 32 || str[i] == '\t')
			i--;
		end = i;
		while (str[i] && (str[i] != 32 && str[i] != '\t'))
			i--;
		start = i + 1; //start será cero cuando sea la primera palabra de la frase
		flag = start;
		while(start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
		if (flag != 0)
			write(1, " ", 1); 
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
} */


#include <unistd.h>

void rev_wstr(char *str)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int first_word_printed = 0; // Usaremos esta variable para rastrear si ya imprimimos la primera palabra.

    // Mover i al final de la cadena.
    while (str[i])
        i++;
    i--; // Ajustamos i para que apunte al último carácter válido de la cadena.

    while (i >= 0)
    {
        // Saltar los espacios y tabulaciones al final o entre palabras.
        while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
            i--;
        end = i;
        
        // Buscar el inicio de la palabra.
        while (i >= 0 && str[i] != ' ' && str[i] != '\t')
            i--;
        start = i + 1;
        // evitamos asi q se imprima un espacio antes de imprimir la primera palabra 
        // Si no es la primera palabra impresa, imprimir un espacio antes de la siguiente palabra.
        if (first_word_printed == 1) // o simplemente no poner ==
            write(1, " ", 1);
        else
            first_word_printed = 1; // Marcamos que la primera palabra ha sido impresa.

        // Imprimir la palabra actual.
        while (start <= end)
        {
            write(1, &str[start], 1);
            start++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return 0;
}
