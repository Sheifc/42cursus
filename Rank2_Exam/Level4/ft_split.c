/* Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */

#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str) 
{
    char **split = malloc(1000000); // Reserva excesiva de memoria
    char *word;
    int i = 0;
	int j = 0;
	int start = 0;
	int k;

    while (str[i]) 
	{
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') 
		{
        	start = i;
			k = 0;
            while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') 
				i++;
            word = (char *)malloc(i - start + 1);
            while (start < i) 
				word[k++] = str[start++];
            word[k] = '\0';
            split[j++] = word;
        } 
		else
            i++;
    }
    split[j] = NULL; // Finaliza la matriz con NULL
    return (split);
}

int main() {
    char *str = "Este es un   ejemplo de prueba\ncon varios\tdelimitadores.";
    char **words = ft_split(str);
	int i = 0;

    while (words[i] != NULL) 
	{
        printf("Palabra %d: %s\n", i + 1, words[i]);
        free(words[i]); // Libera la memoria de cada palabra
		i++;
    }
    free(words); // Libera el array de punteros
    return 0;
}
