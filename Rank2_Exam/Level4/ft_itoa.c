/* Subject:
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	long n = (long)nbr;
	int len = 0;

	// Calculamos la longitud
	if (n <= 0)
		len++; //sumamos 1 len en el caso de q sea negativo o cero
	long n_copy = n; // Use a copy of n for length calculation to preserve original n
	while (n_copy)
	{
		n_copy /= 10;
		len++;
	}
	// reservamos el char resultante
	char *s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return NULL;
	// añadimos el nulo lo primero
	s[len] = '\0';
	len -= 1;
	// en el caso de q n sea cero, añadimos el cero
	if (n == 0)
		s[0] = '0';
	// si es negativo añadimos el signo y convertimos n en positivo
	else if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	// hacemos la conversion de int a char
	while (n)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (s);
}

int main(void)
{
	int n = -256789;
	char *str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	return 0;
}

/* 
En C, -0 y 0 son equivalentes y representan el mismo valor. 
No hay distinción entre "negativo cero" y "cero" en la representación de enteros en C, 
a diferencia de lo que ocurre en algunos formatos de punto flotante donde sí existe un 
"negativo cero". 
 */

/* 	Eliminado para simplificar:
	long n_copy = n; // Use a copy of n for length calculation to preserve original n
	while (n_copy)
	{
		n_copy /= 10;
		len++;
	}
	char *s = (char *)malloc(sizeof(char) * (len + 1));
 	if (!s)
		return NULL; */

/* 
Este código es una implementación de la función `ft_itoa`, que convierte un número entero (`int`) a una cadena de caracteres (`char *`). La función se descompone en varios pasos principales para realizar esta conversión:

1. **Conversión y preparación inicial:**
   - `long n = (long)nbr;`: Convierte el número entero de entrada `nbr` a `long`. Esto se hace para manejar correctamente los números negativos y el rango completo de valores `int` sin desbordamiento.
   - `int len = 0;`: Inicializa la longitud de la cadena resultante en 0. Esta longitud se ajustará para reflejar el número de dígitos en `nbr`, más espacio para el signo negativo si es necesario.

2. **Cálculo de la longitud de la cadena:**
   - La condición `if (n <= 0) len++;` incrementa `len` si `n` es cero o negativo, ya que se necesitará espacio adicional para el carácter '0' o el signo '-' en la cadena resultante.
   - Se crea una copia de `n` llamada `n_copy` para calcular cuántos dígitos hay en el número sin modificar `n`.
   - El bucle `while (n_copy)` divide `n_copy` por 10 repetidamente para contar el número total de dígitos en `nbr`, incrementando `len` por cada dígito encontrado.

3. **Reserva de memoria para la cadena resultante:**
   - `char *s = (char *)malloc(sizeof(char) * (len + 1));`: Reserva memoria para la cadena resultante, incluyendo espacio para el carácter nulo de terminación (`'\0'`) al final de la cadena.
   - Si `malloc` falla al reservar memoria (es decir, si `s` es `NULL`), la función retorna `NULL` para indicar un error.

4. **Inicialización de la cadena resultante:**
   - `s[len] = '\0';`: Coloca el carácter nulo al final de la cadena para indicar su terminación.
   - Si `n == 0`, coloca '0' al principio de la cadena. Si `n < 0`, coloca un signo '-' al principio y convierte `n` a positivo para facilitar el procesamiento de los dígitos.

5. **Conversión del número a cadena:**
   - El último bucle `while (n)` toma el último dígito de `n` (`n % 10`), lo convierte a su representación ASCII sumando `'0'`, y lo coloca en la posición correcta en la cadena `s`. Luego, divide `n` por 10 para pasar al siguiente dígito.
   - Este proceso se repite hasta que todos los dígitos de `n` se han procesado, llenando la cadena `s` desde el final hacia el principio (excepto el carácter nulo de terminación).

6. **Retorno de la cadena resultante:**
   - Finalmente, la función retorna la cadena `s`, que ahora contiene la representación en caracteres del número entero original `nbr`.

En resumen, `ft_itoa` convierte un número entero a una cadena de caracteres, gestionando cuidadosamente la asignación de memoria, la conversión de dígitos y el manejo de números negativos.
 */