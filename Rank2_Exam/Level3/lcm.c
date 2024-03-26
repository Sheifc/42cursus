/* Subject:
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b); */

/* 
Definición:

Mínimo Común Múltiplo (MCM): Es el número entero más pequeño que es múltiplo de dos o más números.
Máximo Común Divisor (MCD): Es el número entero más grande que divide a dos o más números sin dejar residuo.

El MCM de un conjunto de números es el menor número que todos ellos pueden dividir sin dejar residuo.

Por ejemplo, consideremos los números 4 y 6:

Los múltiplos de 4 son: 4, 8, 12, 16, 20, 24, 28, 32...
Los múltiplos de 6 son: 6, 12, 18, 24, 30, 36, 42...
Si comparamos las listas, vemos que el número más pequeño que aparece en ambas listas es el 12. 
Por lo tanto, el MCM de 4 y 6 es 12.
*/

/* 
1. Calculando todos los múltiplos hasta encontrar un múltiplo común:
En este método, listas los múltiplos de cada entero hasta que encuentres un múltiplo que sea común a ambos números.

Ejemplo: Para calcular el MCM de 4 y 6.

Múltiplos de 4: 4, 8, 12, 16, 20...
Múltiplos de 6: 6, 12, 18, 24...
El primer múltiplo común que encuentras es 12. Por lo tanto, el MCM de 4 y 6 es 12.

2. Usando el Máximo Común Divisor (MCD) de los dos enteros:
Aquí, utilizas la fórmula MCM(x, y) = | x * y | / MCD(x, y), donde | x * y | significa "valor absoluto del producto de x por y".

Ejemplo: Para calcular el MCM de 4 y 6 utilizando su MCD.

Primero, encuentras el MCD de 4 y 6, que es 2.
Luego, usas la fórmula: MCM(4, 6) = | 4 * 6 | / 2 = 24 / 2 = 12.
Así que, usando este método, también encuentras que el MCM de 4 y 6 es 12.
*/

// ALGORITMO DE EUCLIDES Ref: https://www.youtube.com/watch?v=rG9nQe-7is8
/*  
mcd (150, 39) = 3

150 = 39 * 3 + 33 (33 es el resto de la division de 150/39=3.33)
39 = 33 * 1 + 6 // 39/33=1.6
// cualkier divisior de 39 y 33 tambien lo debe de ser del resto 6 (aplicable a todos las lineas de este ejemplo)
33 = 6 * 5 + 3 // 33/6=5.3
6 = 3 * 2 + 0 // 6/3=2

Cada resto q vamos obteniendo es estrictamente mas pequeño q el anterior, obteniendo 
finalmente cero. En ese momento, se puede afirmar que el resto anterior es el maximo comun divisor.
*/

/* 
- Calcular el MCD:
El MCD se puede calcular mediante el algoritmo de Euclides, que se basa en la idea de que el MCD de dos números 
también divide el resto obtenido al dividir el número mayor entre el menor.

- Calcular el MCM:
Una vez que tengamos el MCD, podemos calcular el MCM usando la relación:

MCM(a,b)= ∣a×b∣ / MCD(a,b)

Para los números 150 y 39:

El Máximo Común Divisor (MCD) es 3.
El Mínimo Común Múltiplo (MCM) es 1950.
Esto significa que 3 es el mayor número que divide tanto a 150 como a 39 sin dejar residuo, y 1950 es el menor número que es múltiplo tanto de 150 como de 39.
 */


#include <stdio.h>

unsigned int mcd(unsigned int a, unsigned int b)
{
    unsigned int x = 0;
    unsigned int y = 0;

    if (a > b)
        (x = a) && (y = b);
    else
        (x = b) && (y = a);
    if (y == 0) // la division recursiva acabará cuando el resto de la división sea cero
        return (x);
    else
        return (mcd(y, x % y));
}
/* 
Si y no es 0, la función se llama a sí misma (mcd) con los nuevos valores: y y x % y. 
Aquí, x % y calcula el resto de la división de x entre y, y este valor se pasa como el nuevo segundo argumento. 
La función continúa llamándose a sí misma con nuevos valores hasta que el resto (y) es 0. */

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if ((a == 0) || (b == 0))
        return (0);
    else
        return ((a * b)/ mcd(a, b));
}

int main(void)
{
    unsigned int a = 6, b = 4; // si inviertes los valores debe dar la misma solución
    printf("LCM(%u, %u) = %u\n", a, b, lcm(a, b));
    return (0);
}

// Solución: 12

/* 
En la función que mencionas, no es necesario usar atoi porque los valores de a y b 
ya están definidos como enteros (unsigned int) dentro del programa, específicamente en la función main.

En tu programa, a y b se inicializan directamente con los valores 6 y 4 en la función main. 
Estos son literales enteros, y como tal, ya están en el formato adecuado para ser utilizados directamente 
en cálculos matemáticos y pasados a las funciones mcd y lcm. No hay necesidad de convertirlos desde cadenas 
de caracteres, como sería el caso si los valores vinieran de argumentos de línea de comandos (argv), 
donde sí sería necesario utilizar atoi o una función similar para la conversión.
 */