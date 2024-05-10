/* Subject:
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b); */

void ft_swap(int *a, int *b)
{
	int aux = 0;

	aux = *a;
	*a = *b;
	*b = aux;
}

// To test:

int main(void)
{
	int a[1] = {1};
	int b[1] = {2};

	ft_swap(a, b);
	printf("%d %d", *a, *b);
	return (0);
}
