/* Subject:
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i = i - 1; // movemos i desde el nulo al ultimo caracter
 		while (i >= 0) // igualamos a cero para q tb se imprima el primer indice i = 0
		{
			write(1, &argv[1][i], 1);
			i--;
			// otro modo: omitimos i = i - 1, while (i) write(1, &argv[1][--i], 1);
			//i--; //no sirve xq hay que restar 1 primero ya q la primera posicion es 0
			// por tanto para impirmir 4 letras i debe valer 3 para asi dar 4 vueltas: 3,2,1,0
		}
	}
	write(1, "\n", 1);
}
