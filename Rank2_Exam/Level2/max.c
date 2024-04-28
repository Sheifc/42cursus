/* Subject:
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0. */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	unsigned int i = 1;
	int max;

	if (len == 0)
		return (0);
	
	max = tab[0]; // no necesitamos dereferenciar direccion de memoria por tanto no necesito un puntero a int, sino una variable de int para almacenar el valor solo

	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int main(void)
{
	int tab[] = {5, 7, 3, 1};
	unsigned int len = 4;

	printf("%d", max(tab, len));
}
