/* Subject:
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int *n = malloc(1000000);
    int i = 0;
    
	while(start <= end)
	{
		n[i] = start;
		start++;
		i++;
	}
	while(start >= end)
	{
		n[i] = start;
		start--;
		i++;
	}
    return(n);
}

// To test:

int main()
{
    int *range1 = ft_range(1, 3);
    int *range2 = ft_range(0, -3);
    int *range3 = ft_range(0, 0);

    for (int i = 0; i < 3; ++i) printf("%d ", range1[i]);
    printf("\n");
    for (int i = 0; i < 4; ++i) printf("%d ", range2[i]);
    printf("\n");
    printf("%d\n", range3[0]);
    free(range1);
    free(range2);
    free(range3);
    return (0);
}
