/* Subject:
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

/* 
Para descomponer un número compuesto en sus factores primos se divide el número dado 
por el menor de sus divisores primos. El cociente se vuelve a dividir por el menor de 
sus divisores primos y así sucesivamente con los demás cocientes, hasta llegar a un 
cociente primo que se dividirá por sí mismo.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int n;

    if (argc == 2)
    {
        i = 2;
        n = atoi(argv[1]);

        if (n == 1)
            printf("1");
        while (i <= n)
        {
            if (n % i == 0)
            {
               printf("%d", i);
               n /= i;
               if (n == 1)
                  break;
               printf("*");
            }
            else
                i++;
        }
    }
    printf("\n");
    return 0;
}

/* 
necesitas ajustar el flujo de tu bucle para que i no se incremente en la 
iteración en la que se divide n por i. Es decir, cuando encuentres un factor 
primo y dividas n por i, no debes incrementar i en esa misma iteración, 
porque podrías perder otros factores primos iguales.
*/

/* 
Claro, desglosemos cómo funciona este segmento de código con un ejemplo. Usaremos el número `180` para ilustrar el proceso:

1. **Inicialización**: `n = 180`, `i = 2`.

2. **Comienza el Bucle**:
   - La condición del bucle `while (i <= n)` se verifica. Como `2 <= 180` es verdadero, entramos al bucle.

3. **Primera Iteración**:
   - `if (n % i == 0)`: Verifica si `180 % 2 == 0`, lo cual es verdadero.
   - Se imprime `2`.
   - `n /= i`: Actualiza `n` a `180 / 2 = 90`.
   - `if (n == 1)`: Verifica si `n` es igual a 1, lo cual es falso.
   - Se imprime `*`.
   - No se incrementa `i` porque estamos en la parte `if`, no en `else`.

4. **Segunda Iteración**:
   - Aún `i = 2`, y `n = 90`.
   - `if (90 % 2 == 0)`: Verdadero.
   - Se imprime `2`.
   - `n /= i`: Actualiza `n` a `90 / 2 = 45`.
   - `if (n == 1)`: Falso.
   - Se imprime `*`.
   - `i` no se incrementa.

5. **Tercera Iteración**:
   - `i` sigue siendo 2, pero ahora `n = 45`.
   - `if (45 % 2 == 0)`: Falso.
   - Pasamos al `else`, e incrementamos `i` a 3.

6. **Cuarta Iteración**:
   - Ahora `i = 3`, `n = 45`.
   - `if (45 % 3 == 0)`: Verdadero.
   - Se imprime `3`.
   - `n /= i`: Actualiza `n` a `45 / 3 = 15`.
   - `if (n == 1)`: Falso.
   - Se imprime `*`.
   - `i` no se incrementa.

7. **Iteraciones Subsiguientes**:
   - Continuamos de esta manera. `i` permanecerá en 3 hasta que `n` sea divisible por 3 nuevamente, 
   luego se incrementará a 4, 5, etc., hasta que `n` se convierta en 1.

8. **Conclusión**:
   - Eventualmente, `n` se reduce a 1, y el bucle se rompe. En este punto, 
   se han impreso todos los factores primos de `180`, resultando en `2*2*3*3*5`.

Lo que hace este bucle efectivo es que solo incrementa `i` cuando `n` no es divisible por `i`. 
Esto asegura que todos los factores primos de `n` se encuentren y se impriman en orden ascendente, 
incluso si un mismo número primo divide a `n` varias veces.
 */

/* 
number /= i;: Esta línea divide number por i. 
En la factorización de primos, cuando encuentras un divisor primo 
(es decir, un número i que divide exactamente a number), divides number 
por ese divisor primo para continuar factorizando el resultado. 
Por ejemplo, si number es 12 y i es 2, después de number /= i;, 
number será 6. Esto se hace para descomponer number en factores primos 
más pequeños.

i = 1;: Después de dividir number por i, reinicias i a 1. 
Esto se hace para asegurarse de que verificas todos los posibles divisores 
primos desde el principio después de cada división. Por ejemplo, 
si number se ha dividido por 2 y ahora es 6, quieres volver a empezar 
desde 2 en la próxima iteración para verificar si 2 es nuevamente un divisor
(lo cual es cierto en este caso). Si no reiniciaras i a 1, perderías algunos 
factores primos, especialmente si un mismo número primo divide a number varias 
veces.
 */

/* 
Mi version: Inicialización de i a 2: Comienzas con i igual a 2. 
Esto es una mejora en términos de eficiencia porque el 2 es el único número 
primo par, y después de 2, solo necesitas considerar números impares para la 
factorización prima.

Bucle de Factorización: En este código, incrementas i solo después de verificar 
que n % i != 0. Esto es más eficiente porque elimina la necesidad de reiniciar 
i a 1 (o 2 en este caso) después de cada división exitosa. Solo incrementas i 
si n no es divisible por i, lo que reduce el número total de iteraciones en el 
bucle.

División y Reinicio de i: Cuando encuentras un divisor (es decir, n % i == 0), 
divides n por i y reinicias i a 2. Esto asegura que verificas todos los posibles 
divisores primos desde el principio después de cada división. Esto es importante 
porque un número primo puede ser un factor más de una vez. Por ejemplo, en el 
caso de n = 8, necesitas dividir por 2 tres veces.

Condición de Salida del Bucle: Usas if (n == i) para salir del bucle si n se ha 
reducido a un número primo. Esto asegura que no imprimas factores innecesarios 
y termines el proceso de factorización de manera eficiente.
 */
