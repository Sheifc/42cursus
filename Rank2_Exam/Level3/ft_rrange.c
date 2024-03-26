/* Subject:
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */

#include<stdio.h>
#include<stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *n = malloc(1000000);
	int i = 0;

	while(start <= end)
	{
		n[i] = end;
		end--;
		i++;
	}

	while(start >= end)
	{
		n[i] = end;
		end++;
		i++;
	}
	return(n);
}

int main() {
    int *range1 = ft_rrange(1, 3);
    int *range2 = ft_rrange(0, -3);
    int *range3 = ft_rrange(0, 0);

    // Suponiendo que el rango es conocido para la impresión.
    for (int i = 0; i < 3; ++i) printf("%d ", range1[i]);
    printf("\n");

    for (int i = 0; i < 4; ++i) printf("%d ", range2[i]);
    printf("\n");

    printf("%d\n", range3[0]);

    // Liberar memoria
    free(range1);
    free(range2);
    free(range3);

    return 0;
}