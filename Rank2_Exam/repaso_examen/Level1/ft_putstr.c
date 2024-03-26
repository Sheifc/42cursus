#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);

}

int main(void)
{
	char *s = "hola como estas";
	ft_putstr(s);
}