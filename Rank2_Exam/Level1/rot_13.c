/* Subject:
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$> */

#include <unistd.h>

int main (int argc,char **argv)
{
    if(argc == 2)
    {
        char *str = argv[1];
        int i = 0;
        
        while(str[i])
        {
            if((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
                {
                    str[i] = str[i] + 13;
                    write(1,&str[i],1);
                }
            else if((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
                {
                    str[i] = str[i] - 13;
                    write(1,&str[i],1);
                }
            else
                write(1,&str[i],1);
            i++;
        }
    }
    write(1,"\n",1);
}

/* Otro modo:

int main(int argc, char **argv)
{
	int i; 

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a';
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A';
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

El valor ASCII de 'b' es 98.
La operación es (98−97+13)%26+97.
Esto se traduce en (1+13)%26+97, que es (14%26)+97(14%26)+97.
El resultado de 14%26 es 14, ya que 14 es menor que 26 y no se reduce.
Finalmente, 14+97 es 111, que es el valor ASCII de 'o'.

División: Se divide el dividendo por el divisor.
Resultado de la División: Se calcula cuántas veces el divisor cabe completamente en el dividendo.
Residuo: En lugar de dar el resultado de la división, la operación del módulo da el residuo de esta división.
Por ejemplo, si consideramos 14%26:

División: 14/26 da como resultado aproximadamente 0.54, pero solo nos interesan los números enteros en esta operación.
Resultado de la División: 26 no cabe completamente en 14 ni una sola vez (puesto que 14 es menor que 26).
Residuo: El residuo de dividir 14 entre 26 es simplemente 14, ya que no hay suficiente para "completar" un 26. */
