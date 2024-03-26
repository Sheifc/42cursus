/* Subject:

Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */

/* Erroneamente, he resuelto el problema comprobando si el numero es par:
	if (n % 2 == 0)
		return (1);
	//if (n % 2 != 0) asi me daba error al compilar xq la funcion debe retornar int para todos los casos
	else
		return (0); */

/* 
Inicialmente, nbr es 1 (que es 2^0).
1. En la primera iteración, si n no es 1, nbr se multiplica por 2. 
Ahora nbr es 2 (que es 2^1).
2. En la segunda iteración, si n no es 2, nbr se multiplica por 2 nuevamente. 
Ahora nbr es 4 (que es 2^2).

Este proceso se repite, con nbr tomando valores de 8 (2^3), 16 (2^4), 32 (2^5), y así sucesivamente.
Cada vez que nbr se multiplica por 2, efectivamente estás pasando a la siguiente potencia de 2. 
Y en cada iteración, comparas este nbr (que representa la potencia de 2 actual en la secuencia) con n. 
Si en algún momento nbr es igual a n, eso significa que n es una potencia de 2, 
porque coincide con una de las potencias de 2 generadas en el bucle.

Si nbr se hace más grande que n sin encontrar una igualdad, sabes que n no puede ser una potencia de 2, 
porque si lo fuera, habrías encontrado una igualdad en una de las iteraciones anteriores del bucle.
*/

#include <stdio.h>

/* int	    is_power_of_2(unsigned int n)
{
	unsigned int nbr = 1; // 1 = 2^0

	if (n == 0) // 0 no es power of 2
		return (0);
	while (1)
	{
		if (nbr == n) // si n no es 1, nbr se multiplica por 2, xq no entra en el if ni en el else, pasa a nbr *= 2
			return (1);
		else if (nbr > n)
			return (0);
		nbr *= 2; // si entra n=12, primera vuelta pasa aki y nbr*2 = 1*2=2, 
		//segunda vuelta, nbr*2 = 2*2=4, tercera 4*2=8, cuarta 8*2=16, entonces entra en el else if y retorna 0
	}
} */

// Otro modo:

/* int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 = 0)
		n /= 2;
	if (n == 1) // es la primera condición q incumplira n % 2, es el resultado de la primera div 2/2 = 1
		return (1);
	return (0);
} */

// Otro modo: recursividad: pasa el grademe

int is_power_of_2(unsigned int n)
{
	if (n == 0) return (0);
	if (n == 1) return (1);
	if (n % 2 == 0)
		return (is_power_of_2(n/2));
	return (0);
}

int main(void)
{
	unsigned int n = 12;
	printf("%d", is_power_of_2(n));
}

/* Resolución del problema con bits: 
Here's how you can implement the `is_power_of_2` function in C. 
This function will check if the given number is a power of 2 by continuously dividing the number by 2 
(if it's even) and checking if it eventually equals 1. 
Alternatively, it uses the properties of binary numbers to perform a quick check.

```c
int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n & (n - 1)) == 0;
}
```

Here's an explanation of how the function works:

- **Base case check**: If `n` is 0, the function returns 0 because 0 is not a power of 2.
- **Bitwise AND operation**: The expression `(n & (n - 1))` uses a bitwise AND operation between `n` and `n-1`. 
For numbers that are powers of 2, their binary representation has a single 1 followed by 0s 
(like `1000` for 8, `100` for 4, etc.). Subtracting 1 from such a number flips all the bits after 
the rightmost 1 (including the rightmost 1 itself). So, performing an AND operation between such a 
number and its previous number always yields 0 (e.g., `1000 & 0111 = 0000`). For numbers that are not 
powers of 2, this is not the case, and the result of the AND operation will not be 0.

- **Return value**: The function returns 1 if the result of the operation is 0 (indicating that 
the number is a power of 2), otherwise, it returns 0.

"Bitwise" se refiere a operaciones que se realizan directamente sobre los bits, que son las unidades 
más básicas de datos en informática, representando 0 o 1. En C, y en muchos otros lenguajes de programación, 
hay varios operadores bitwise que permiten manipular números a nivel de bit. Aquí están los más comunes:

1. **AND (`&`)**: Compara cada bit de dos números y devuelve un número cuyo bit está activado (1) 
solo si ambos bits en la misma posición en los números originales están activados. Por ejemplo, 
`5 & 3` daría `1` porque `101 & 011 = 001`.

2. **OR (`|`)**: Compara cada bit de dos números y devuelve un número cuyo bit está activado si al menos 
uno de los bits en la misma posición en los números originales está activado. Por ejemplo, `5 | 3` daría `7` 
porque `101 | 011 = 111`.

3. **XOR (`^`)**: Compara cada bit de dos números y devuelve un número cuyo bit está activado solo si 
uno de los bits (pero no ambos) en la misma posición en los números originales está activado. Por ejemplo, 
`5 ^ 3` daría `6` porque `101 ^ 011 = 110`.

4. **NOT (`~`)**: Invierte todos los bits de un número. Si el bit es 1, se convierte en 0, y viceversa. 
Por ejemplo, `~5` en un contexto de 8 bits daría `250` porque `~00000101 = 11111010`.

5. **Shift Left (`<<`)**: Desplaza todos los bits de un número hacia la izquierda una cierta cantidad de veces. 
Por ejemplo, `5 << 1` daría `10` porque `101` desplazado una posición a la izquierda se convierte en `1010`.

6. **Shift Right (`>>`)**: Desplaza todos los bits de un número hacia la derecha una cierta cantidad de veces. 
Por ejemplo, `5 >> 1` daría `2` porque `101` desplazado una posición a la derecha se convierte en `010`.

Estas operaciones son fundamentales en la programación a bajo nivel, como en el desarrollo de sistemas, 
drivers, o programas que requieren una manipulación eficiente de la memoria y los datos a nivel de bit.
 */
