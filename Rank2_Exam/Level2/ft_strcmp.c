/* Subject:
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/
// no es correcta porque solo compara el primer caracter del string
/* int    ft_strcmp(char *s1, char *s2)
{
	if (!*s1)
		return (-1);
	if (!*s2)
		return (1);
	if (*s1 == *s2)
		return (0);
	return(*s1 - *s2);
} */

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%d\n", ft_strcmp("hello World", "hello world"));
	printf("%d\n", strcmp("hello World", "hello world"));
	printf("%d\n", ft_strcmp("hello", "hello"));
	printf("%d\n", strcmp("hello", "hello"));
}

// Outputs: 

/* Análisis de Resultados
Comparación de "hello World" vs. "hello world": La diferencia esperada es entre las letras 'W' y 'w', que en ASCII es 32 
(dado que 'W' = 87 y 'w' = 119). La función strcmp del sistema probablemente normaliza este valor a -1 
para indicar que la primera cadena es menor, mientras que tu implementación devuelve exactamente 32 o -32, 
dependiendo de cuál implementación se ejecutó basado en la descripción. 

Comparación de "hello" vs. "Hello": La diferencia aquí es entre 'h' y 'H', que en ASCII es 32. 
Esto se refleja correctamente en la implementación, pero la función del sistema normaliza los valores a 1 o -1 
para indicar cuál cadena es mayor o menor, no la diferencia exacta de los caracteres.

Conclusión
Es importante recordar que strcmp retorna 0 si las cadenas son iguales, un valor negativo si la primera cadena 
es menor que la segunda, y un valor positivo si la primera cadena es mayor. La normalización exacta de los valores 
(como convertir cualquier diferencia a -1, 0, o 1) no es parte de la especificación de strcmp, 
aunque algunas implementaciones pueden comportarse así para indicar simplemente cuál cadena es mayor o menor 
sin dar la diferencia exacta de los caracteres ASCII. */

/* 
#include <stdio.h>

int ft_strcmp(const char *s1, const char *s2) 
{
    while (*s1 != '\0' && *s1 == *s2) 
	{
        s1++;
        s2++;
    }
    if ((unsigned char)*s1 < (unsigned char)*s2) 
        return -1; // La primera cadena es menor que la segunda
	else if ((unsigned char)*s1 > (unsigned char)*s2) 
        return 1; // La primera cadena es mayor que la segunda
    else 
        return 0; // Las cadenas son iguales
}

int main(void) {
    printf("%d\n", ft_strcmp("hello World", "hello world")); // Esperado: -1 o 1, dependiendo de la implementación específica
    printf("%d\n", strcmp("hello World", "hello world"));    // Resultado del sistema
    printf("%d\n", ft_strcmp("hello", "Hello"));             // Esperado: 1, ya que 'h' es mayor que 'H'
    printf("%d\n", strcmp("hello", "Hello"));                // Resultado del sistema
}

 */