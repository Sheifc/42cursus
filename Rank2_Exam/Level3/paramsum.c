/* Subject:
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
 */

#include <unistd.h>

void ft_putnbr(int n)
{
	char c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0'; // para la conversión de número a character
	write(1, &c, 1);
}
// sumar '0' (que es 48) a un dígito convierte ese dígito en su representación de carácter ASCII.

int main(int argc, char **argv)
{
	(void)argv; // asi lo anulamos cd no le damos uso, cuidado q los parentesis van en void y no en argv

	if (argc > 1)
		ft_putnbr(argc - 1);
	else if (argc == 1)
	//else
		write(1, "0", 1);
	write(1, "\n", 1);
}
/*
Problema con write(1, &i, 1);:
Esta línea intenta escribir el valor de i directamente a la salida estándar. Sin embargo, write funciona a nivel de bytes, y esta llamada solo escribirá el byte menos significativo de i. Además, no convertirá i a una cadena de caracteres, por lo que no se mostrará correctamente el número.

Falta de Conversión de Número a Cadena: putnbr
Para mostrar correctamente el número, primero hay que convertir el valor de i a una cadena de caracteres. 
 */
