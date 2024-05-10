/* Subject:
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> 
*/

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	n = 0;

	while (*s)
		n = n * 10 + *s++ - '0';
	return (n);
}

int	ft_is_prime(int n)
{
	int	divisor = 2;

	if (n <= 1)
		return (0);
	while (divisor * divisor <= n)
	{
		if (n % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}

void	ft_put_nbr(int n)
{
	char c;

	if (n >= 10)
		ft_put_nbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		int	n = ft_atoi(argv[1]);
		int	sum = 0;

		while (n >= 2)
		{
			if (ft_is_prime(n))
				sum += n;
			n--;
		}
		ft_put_nbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
