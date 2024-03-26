/* Subject:
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

/* the implementation of the function ft_atoi_base which converts a string in 
a given base (up to base 16) to an integer in base 10. The function handles 
negative numbers and both lowercase and uppercase letters for bases above 10. */

/* 
La función ft_atoi_base, el "número" que se procesa no es un número en el sentido convencional 
(es decir, no es un valor numérico como un int o un float), sino que es una cadena de caracteres 
(string) compuesta por letras y/o números. Esta cadena representa un número en una base específica, 
y cada carácter de la cadena es un dígito en esa base. La función se encarga de convertir 
esta representación de cadena en un valor numérico entero (en base 10).
 */

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// convierte un caracter c al valor numerico correspondiente segun la base
int get_digit(char c, int str_base)
{
	int max_digit;

	// convertimos el numero str_base al valor de la base correspondiente "0123456789abcdef"
	if (str_base <= 10) // int to numero
		max_digit = str_base + '0'; // xej: 2+48=50 q es 2 en ascii 9+48=57
	else
		max_digit = str_base - 10 + 'a'; //str_base=numero x tanto si str_base es 16, 16 - 10 + 97 = 103 es g en ascii??
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0'); // char to numero
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (c + 10 - 'a'); // c = 'a' = 97 => 97 + 10 - 97 = 10
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int n = 0;
	int sign = 1;
	int digit;

    // Verificar que la base esté dentro del rango válido
    if (str_base < 2 || str_base > 16)
        return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{	
		n = n * str_base + digit;
		str++; // to multiply by the sign in each iteration may lead to an overflow of int
	}
	// Si el bucle terminó debido a un carácter no válido y no al final de la cadena, retorna 0
	if (*str != '\0') 
		return (0);
	return (n * sign);
}

/////// Documentación del código ////////////

/* char	to_lower(char c) // convierte todo a minuscula
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32); // 32 is the difference between 'a' - 'A'
	return (c);
}

// convierte un caracter c al valor numerico correspondiente segun la base
int get_digit(char c, int str_base)
{
	int max_digit;

	// convertimos el numero str_base al valor de la base correspondiente "01234566789abcdef"
	if (str_base <= 10) // int to numero
		max_digit = str_base + '0'; // Si str_base es 2, entonces max_digit será '0' + 2, 
		//lo cual dará como resultado el carácter '2'
	else
		max_digit = str_base - 10 + 'a'; //str_base=numero x tanto si str_base es 16, 
		// entonces max_digit será 'a' + (16 - 10), lo que resulta en 'f'

	// se convierte a su equivalente numérico restando el valor ASCII de '0'
	Por ejemplo, el carácter '0' se convierte en el número 0, '1' se convierte en 1, 
	y así sucesivamente hasta '9'.
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0'); // char to numero
	Se convierte a su equivalente numérico para bases superiores a 10. 
	Esto se hace sumando 10 y restando el valor ASCII de 'a'. 
	Por ejemplo, 'a' se convierte en 10, 'b' en 11, y así sucesivamente hasta 'f', 
	que se convierte en 15.
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (c + 10 - 'a'); // c = 'a' = 97 => 97 + 10 - 97 = 10
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int n = 0;
	int sign = 1;
	int digit;

    // Verificar que la base esté dentro del rango válido
    if (str_base < 2 || str_base > 16)
        return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{	
		n = n * str_base + digit;
		str++; // to multiply by the sign in each iteration may lead to an overflow of int
	}
	return (n * sign);
} */

int main()
{
    // Pruebas con diferentes strings y bases
    printf("Convertir '120' en base 16 a decimal: %d\n", ft_atoi_base("120", 16));
    printf("Convertir '101' en base 2 a decimal: %d\n", ft_atoi_base("101", 2));
    printf("Convertir '7b' en base 16 a decimal: %d\n", ft_atoi_base("7b", 16));
    printf("Convertir '-10' en base 10 a decimal: %d\n", ft_atoi_base("-10", 10));
    printf("Convertir 'FF' en base 16 a decimal: %d\n", ft_atoi_base("FF", 16));
    printf("Convertir '21' en base 8 a decimal: %d\n", ft_atoi_base("21", 8));
    printf("Convertir 'z' en base 36 (no válido): %d\n", ft_atoi_base("z", 36)); // Caso no válido
    printf("Convertir '11' en base 1 (no válido): %d\n", ft_atoi_base("11", 1)); // Caso no válido

/* Solución:
Convertir '120' en base 16 a decimal: 288
Convertir '101' en base 2 a decimal: 5
Convertir '7b' en base 16 a decimal: 123
Convertir '-10' en base 10 a decimal: -10
Convertir 'FF' en base 16 a decimal: 255
Convertir '21' en base 8 a decimal: 17
Convertir 'z' en base 36 (no válido): 0
Convertir '11' en base 1 (no válido): 0 */

// Asumiendo que ya tienes definidas las funciones ft_atoi_base y get_digit en tu código.

//int main() {
    // Prueba en base 2, el máximo dígito es '1'.
    printf("Convertir '1' en base 2 a decimal: %d\n", ft_atoi_base("1", 2));

    // Prueba en base 10, el máximo dígito es '9'.
    printf("Convertir '9' en base 10 a decimal: %d\n", ft_atoi_base("9", 10));

    // Prueba en base 16, el máximo dígito es 'f'.
    printf("Convertir 'f' en base 16 a decimal: %d\n", ft_atoi_base("f", 16));

    // Prueba en base 16, intentando exceder el máximo dígito con 'g'.
    printf("Convertir 'g' en base 16 a decimal (debe ser inválido): %d\n", ft_atoi_base("g", 16));

    // Prueba en base 10, intentando exceder el máximo dígito con 'a'.
    printf("Convertir 'a' en base 10 a decimal (debe ser inválido): %d\n", ft_atoi_base("a", 10));

    // Prueba con el máximo valor permitido para base 16.
    printf("Convertir 'ff' en base 16 a decimal: %d\n", ft_atoi_base("ff", 16));

    // Prueba con el máximo valor permitido para base 16, incluyendo un valor no permitido 'g'.
    printf("Convertir 'fg' en base 16 a decimal (debe ser inválido): %d\n", ft_atoi_base("fg", 16));

    return 0;
}

/* Solución:
Convertir '1' en base 2 a decimal: 1
Convertir '9' en base 10 a decimal: 9
Convertir 'f' en base 16 a decimal: 15
Convertir 'g' en base 16 a decimal (debe ser inválido): 0
Convertir 'a' en base 10 a decimal (debe ser inválido): 0
Convertir 'ff' en base 16 a decimal: 255
Convertir 'fg' en base 16 a decimal (debe ser inválido): 0 

 */