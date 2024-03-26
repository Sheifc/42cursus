/* Subject:
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept); */

#include <string.h>
#include <stdio.h>

// Rossi:

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i])
	{
		if (ft_strchr(accept, s[i]) == 0) // si no lo encuentra rompe el bucle y devuelve i
			break;
		i++;
	}
	return (i);
}

// Otro modo:
/* size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j = 0;

	while (s[i])
	{
		j = 0;
		while (accept[j] && s[i] != accept[j])
			j++;
 		if (accept[j] == '\0')
			break;
		i++;
	}
	return (i);
} */

int main (void)
{
	char *s = "hola";
	char *s2 = "ohpa";
	printf("%luResultado:\n", ft_strspn(s, s2));
	printf("%luResultado:", strspn(s, s2));
}

/* ./a.out        
2
2%                         
*/

/* Las funciones `strcspn` y `strspn` en C son utilizadas para realizar operaciones relacionadas con cadenas de caracteres (strings). Aunque ambas funciones trabajan con strings, tienen propósitos distintos.

### `strcspn`

La función `strcspn` busca en una cadena el primer carácter que coincida con cualquiera de los caracteres de otra cadena.

**Prototipo:**
```c
size_t strcspn(const char *str1, const char *str2);
```

**Parámetros:**
- `str1`: La cadena en la que se realiza la búsqueda.
- `str2`: La cadena que contiene los caracteres que no queremos encontrar en `str1`.

**Funcionamiento:**
- La función `strcspn` recorre `str1` carácter por carácter.
- Para cada carácter en `str1`, la función verifica si ese carácter aparece en `str2`.
- Si encuentra un carácter en `str1` que está presente en `str2`, detiene la búsqueda.
- Devuelve la cantidad de caracteres recorridos en `str1` antes de encontrar el primer carácter coincidente.

**Valor de retorno:**
- Devuelve el número de caracteres en `str1` que no están en `str2` (es decir, el índice del primer carácter coincidente).

### `strspn`

La función `strspn`, por otro lado, busca en una cadena el primer carácter que no coincida con ninguno de los 
caracteres de otra cadena.

**Prototipo:**
```c
size_t strspn(const char *str1, const char *str2);
```

**Parámetros:**
- `str1`: La cadena en la que se realiza la búsqueda.
- `str2`: La cadena que contiene los caracteres que queremos encontrar en `str1`.

**Funcionamiento:**
- La función `strspn` recorre `str1` carácter por carácter.
- Para cada carácter en `str1`, la función verifica si ese carácter no aparece en `str2`.
- Si encuentra un carácter en `str1` que no está presente en `str2`, detiene la búsqueda.
- Devuelve la cantidad de caracteres recorridos en `str1` antes de encontrar el primer carácter no coincidente.

**Valor de retorno:**
- Devuelve el número de caracteres iniciales en `str1` que están contenidos en `str2`.

En resumen, `strcspn` cuenta cuántos caracteres hay en `str1` antes de encontrar un carácter 
que también esté en `str2`, mientras que `strspn` cuenta cuántos caracteres hay en `str1` 
que solo contienen caracteres de `str2`. Ambas funciones son útiles para operaciones de análisis de strings, 
como la validación de entradas o el procesamiento de datos de texto. */

