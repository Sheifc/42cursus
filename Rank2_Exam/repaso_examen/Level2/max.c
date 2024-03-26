#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	if (len == 0)
		return (0);
	unsigned int i = 1;
	int max = tab[0];

	while(i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int main(void)
{
	int tab[4] = {5, 7, 3, 1};
	unsigned int len = 4;

	printf("%d", max(tab, len));
}