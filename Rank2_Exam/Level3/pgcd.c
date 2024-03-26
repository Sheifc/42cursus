/* Subject:
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int mcd(unsigned int a, unsigned int b)
{
    unsigned int x = 0;
    unsigned int y = 0;

    if (a > b)
        (x = a) && (y = b);
    else
        (x = b) && (y = a);
    if (y == 0)
        return (x);
    else
        return (mcd(y, x % y));
}

int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d",mcd(atoi(argv[1]), atoi(argv[2])));
	printf("\n");
}
/* 
Línea de Comandos a argv: Cuando ejecutas un programa con argumentos 
(por ejemplo, ./programa 123 456), estos argumentos se pasan al programa y se almacenan en argv, 
que es un array de cadenas de caracteres (char*).

Conversión con atoi: La función atoi toma una cadena de caracteres (char*) y 
trata de convertirla en un número entero (int). Si la cadena contiene caracteres que no son dígitos, 
atoi los ignora y convierte hasta donde pueda. Si la cadena no comienza con dígitos, atoi devuelve 0.

Uso en mcd: En tu programa, mcd(atoi(argv[1]), atoi(argv[2])) convierte los dos primeros argumentos 
de la línea de comandos a enteros y luego los pasa a la función mcd. 

Máximo Común Divisor (MCD): Es el número entero más grande que divide a dos o más números sin dejar residuo.
*/

/* 
El algoritmo de Euclides es un método antiguo y eficiente para calcular el máximo común divisor (MCD) de dos números. 
El MCD es el mayor número que divide a ambos números sin dejar residuo. 
El algoritmo se basa en la premisa de que el MCD de dos números también divide el resto de la división del mayor 
entre el menor.

El algoritmo sigue estos pasos:

Comparar los dos números para determinar cuál es mayor (no importa si uno es mayor que el otro para la implementación 
que se discute, pero es parte del algoritmo original).
Dividir el número mayor entre el menor y tomar el resto de esta división.
Reemplazar el número mayor con el menor y el número menor con el resto obtenido en el paso 2.
Repetir los pasos 2 y 3 hasta que el resto sea 0. Cuando esto sucede, el número menor actual es el MCD 
de los dos números originales.

Si los números iniciales son 48 y 18:

Primera llamada a mcd(48, 18): x = 48, y = 18. Se calcula x % y = 12.
Llamada recursiva mcd(18, 12): Ahora x = 18, y = 12. Se calcula x % y = 6.
Llamada recursiva mcd(12, 6): Ahora x = 12, y = 6. Se calcula x % y = 0.
Como el resto es ahora 0, el MCD es y de la llamada anterior, que es 6.
Este proceso recursivo continúa hasta que el resto es 0, 
momento en el cual el valor de y es el MCD de los números originales.
 */

/* Lo que ocurre en el programa:
La línea de código (mcd(y, x % y)) dentro de la función mcd realiza el cálculo del máximo común divisor (MCD) 
entre dos números enteros a y b utilizando el algoritmo de Euclides. El algoritmo funciona de la siguiente manera:

Compara los dos números a y b para determinar cuál es mayor. El mayor se almacena en x y el menor en y.
Verifica si y es cero. Si es así, retorna x como el MCD, porque el MCD de un número y cero es el número mismo.
Si y no es cero, llama recursivamente a la función mcd con los argumentos y y el resto de dividir x entre y (x % y).
Este proceso se repite, reduciendo los números en cada llamada recursiva, hasta que y sea cero, momento en el cual 
se retorna el valor de x, que en ese punto es el MCD de los números originales.
 */
