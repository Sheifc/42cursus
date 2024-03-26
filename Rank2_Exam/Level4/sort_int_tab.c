/* 
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int aux = 0;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			aux = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = aux;
			i = 0;
		}
		else
			i++;
	}
}
#include <stdio.h>

int main(void)
{
	unsigned int i = 0;
	unsigned int size = 5;
	int tab[] = {8, 3, 9, 9, 7};
	sort_int_tab (tab, size);
	while (i < size)
	{
		printf ("%d", tab[i]);
		i++;
	}
}