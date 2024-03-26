/* Subject:
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$> */

#include <unistd.h>

void hidenp (char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while(s2[j])
	{
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write(1,"1",1);
	else 
		write(1,"0",1);
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		hidenp(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}

/* 
Este código define una función `hidenp` que verifica si la secuencia de caracteres de la cadena 
`s1` se encuentra en la misma secuencia en la cadena `s2`, aunque posiblemente con otros 
caracteres entre medio. Si `s1` está "escondida" en `s2` de esta forma, la función devuelve `1`; 
de lo contrario, devuelve `0`.

Funcionamiento detallado:
- `i` se utiliza para iterar sobre los caracteres de `s1`, y `j` para iterar sobre los caracteres 
de `s2`.
- Dentro del bucle `while`, que recorre `s2` con `j`, se verifica si el carácter actual de `s2[j]` 
coincide con el carácter actual de `s1[i]`.
- Si hay una coincidencia, `i` se incrementa para buscar el siguiente carácter de `s1` en el resto 
de `s2`.
- Si no hay coincidencia entre el carácter actual de s2[j] y s1[i], el bucle simplemente continúa 
sin incrementar i. En este caso, solo j se incrementa para pasar al siguiente carácter de s2. 
Esto permite seguir buscando en s2 la próxima coincidencia potencial para el carácter actual 
de s1[i] sin avanzar a verificar el siguiente carácter de s1, manteniendo i fijo hasta que se 
encuentre una coincidencia.
- Si se alcanza el final de `s1` (`s1[i] == '\0'`), significa que todos los caracteres de `s1` 
se encontraron en `s2` en el orden correcto, y se devuelve `1`.
- Si se recorre toda `s2` sin encontrar `s1` completamente, se devuelve `0`.

La función `main` utiliza `hidenp` para comprobar si la cadena en `argv[1]` está "escondida" 
dentro de la cadena en `argv[2]`. Imprime `1` si es verdadero y `0` si es falso, seguido de 
un salto de línea. Esto solo ocurre si se proporcionan exactamente 3 argumentos al programa 
(`argc == 3`), teniendo en cuenta que el primer argumento (`argv[0]`) es el nombre del programa.
 */