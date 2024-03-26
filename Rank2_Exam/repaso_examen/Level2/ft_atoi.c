#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
	int sign = 1;
	int n = 0;

	while (*str == 32 || *str >= 9 && *str <= 13)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9') //se me olvidó poner esa condición
		n = n * 10 + *str++ - '0';
	return (n * sign);
}
int main(void)
{
	const char *str = " a";
	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
}