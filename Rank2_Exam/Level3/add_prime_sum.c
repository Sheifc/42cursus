/* Subject:
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> 
*/

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	n = 0;

	while (*s)
		n = n * 10 + *s++ - '0';
	return (n);
}

int	ft_is_prime(int n)
{
	int	divisor = 2;

	if (n <= 1)
		return (0);
	// si un número n no tiene divisores menores o iguales a la raíz cuadrada de n, 
	// entonces definitivamente es primo
	while (divisor * divisor <= n)
	{
		if (n % divisor == 0) // si esto se cumple no es primo
			return (0);
		divisor++;
	}
	return (1);
}

void	ft_put_nbr(int n)
{
	char c;
	if (n >= 10)
		ft_put_nbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		int	n = ft_atoi(argv[1]);
		int	sum = 0;

		// por debajo de 2 no hay numeros primos
		// comprobamos si todos los numeros por debajo de n incluido n son primos
		while (n >= 2)
		{
			if (ft_is_prime(n))
				sum += n;
			n--;
		}
		ft_put_nbr(sum);
	}
	else
		write(1, "0", 1); //sino al no pasarle argumentos no escribe cero
	write(1, "\n", 1);
	return (0);
}




// un número primo es un número natural mayor que 1 
// que tiene únicamente dos divisores positivos distintos: él mismo y el 1.

/* 
Un número n es primo si no existe ningún número d (donde 2 <= d <= raiz cuadrada de n) 
tal que `n % d == 0`. Si tal `d` existe, significa que `n` es divisible por `d` sin dejar resto, 
y por lo tanto, `n` no es un número primo.*/

/* 
La raíz cuadrada de un número x se define como el número 'y' tal que y * y = x. 
En notación matemática, esto se escribe como y = raiz cuadrada de x.
Por ejemplo, la raíz cuadrada de 9 es 3, porque 3×3=9.
*/

/* #include <unistd.h>

// lo primero que hay que hacer es pasar este numero que viene en formato string por argumento a int

int ft_atoi(char *str)
{
	int n = 0;

	while (*str)
		n = n * 10 + *str++ - '0';
	return (n);
} */

// todos los numeros son divisibles por 1, asi q empezamos comprobando divisores por 2, 
// desde 2 hasta la raiz cuadrada de n, divisor * divisor = n

// 2 comprobaciones: comprobar hasta la raiz cuadrada de n y verificar si n es divisible por el divisor
/* int ft_is_prime(int n)
{
	if (n <= 1)
		return (0);
	int divisor = 2;

	while (divisor * divisor <= n)
	{
		if (n % divisor == 0)
			return (0);
		divisor++;
	}
	return (1); // no lo encuentra, entonces es TRUE, es primo
} */
// calculamos la suma de todos los números primos que sean inferiores o iguales a un número n dado
// primero comprobamos si todos los numeros por debajo de n incluido n son primos

/* int ft_sum_prime(int n)
{
	int sum = 0;
	int nbr = 2;

	while (nbr <= n)
	{
		if ((ft_is_prime(nbr)) == 1)
			sum = sum + nbr; // sum += nbr
		nbr++;
	}
	return (sum);
} */

/* 
Cuando usas write(1, &sum, 1), estás diciendo: "Escribe 1 byte de datos desde la dirección de sum 
al descriptor de archivo 1 (que es la salida estándar)".

La Naturaleza de sum: sum es un entero, y su representación en memoria no es la misma que la representación 
de los caracteres que deseas imprimir. Por tanto, no se puede usar un write(1, &sum, 1) en la función 
ft_sum_prime y se requiere de la función ft_putnbr que convierte el entero a caracter
*/

/* void ft_putnbr(int n)
{
	char c; // un caracter, no un string

	if (n >= 10)
		ft_putnbr(n/10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		int sum = ft_sum_prime(n);
		ft_putnbr(sum);
	}
	else
        write(1, "0", 1);
	write(1, "\n", 1);
} */
/* int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		int sum = 0;

		while (sum <= n)
		{
			if (ft_is_prime(n) == 1)
				sum += n;
			n--;
		}
		ft_putnbr(sum);
	}
	else
        write(1, "0", 1);
	write(1, "\n", 1);
} */

/* 
Ejemplo de comprobación es primo:

### Ejemplo con un Número Primo: 7

**Número**: 7

1. **Inicio**: `divisor = 2`
2. **Primera Iteración**: 
   - Comprobamos si `2 * 2 <= 7` (4 <= 7), es verdadero, por lo que seguimos.
   - Verificamos si `7 % 2 == 0` (¿7 es divisible por 2?), no lo es.
   - Incrementamos `divisor` a 3.
3. **Segunda Iteración**:
   - Comprobamos si `3 * 3 <= 7` (9 <= 7), es falso, por lo que detenemos el bucle.
   - No necesitamos verificar si `7 % 3 == 0` porque ya salimos del bucle.

Como no encontramos ningún divisor de 7 entre 2 y la raíz cuadrada de 7, concluimos que 7 es primo.

### Ejemplo con un Número No Primo: 8

**Número**: 8

1. **Inicio**: `divisor = 2`
2. **Primera Iteración**: 
   - Comprobamos si `2 * 2 <= 8` (4 <= 8), es verdadero, por lo que seguimos.
   - Verificamos si `8 % 2 == 0` (¿8 es divisible por 2?), sí lo es.
   - Como encontramos un divisor, concluimos que 8 no es primo y detenemos el proceso.

En el caso de 8, inmediatamente encontramos que es divisible por 2, lo que demuestra que no es un número primo.

Caso 1: El Argumento es 0
Cuando ejecutas el programa con 0 como argumento (ej., ./a.out 0), el flujo del programa es el siguiente:

Conversión del Argumento a Entero: La función ft_atoi convierte el argumento "0" a su equivalente numérico 0.
Inicialización de la Suma: Se inicializa sum a 0.
Bucle While para la Suma de Números Primos: El programa entra en un bucle while que se ejecutará mientras 
n >= 2. Dado que n es 0 en este caso, el bucle no se ejecuta ni una sola vez, ya que la condición n >= 2 
es falsa de inmediato.
Impresión del Resultado: Como el bucle no se ejecutó, sum permanece en 0, y el programa imprime ese valor.
*/
