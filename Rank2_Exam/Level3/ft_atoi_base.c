/* Subject:
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int get_digit(char c, int str_base)
{
	int max_digit;

	if (str_base <= 10)
		max_digit = str_base + '0';
	else
		max_digit = str_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (c + 10 - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int n = 0;
	int sign = 1;
	int digit;

    if (str_base < 2 || str_base > 16)
        return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		n = n * str_base + digit;
		str++;
	}
	if (*str != '\0') 
		return (0);
	return (n * sign);
}

// To test:

int main()
{
    printf("Convertir '120' en base 16 a decimal: %d\n", ft_atoi_base("120", 16));
    printf("Convertir '101' en base 2 a decimal: %d\n", ft_atoi_base("101", 2));
    printf("Convertir '7b' en base 16 a decimal: %d\n", ft_atoi_base("7b", 16));
    printf("Convertir '-10' en base 10 a decimal: %d\n", ft_atoi_base("-10", 10));
    printf("Convertir 'FF' en base 16 a decimal: %d\n", ft_atoi_base("FF", 16));
    printf("Convertir '21' en base 8 a decimal: %d\n", ft_atoi_base("21", 8));
    printf("Convertir 'z' en base 36 (no válido): %d\n", ft_atoi_base("z", 36)); // Case not valid
    printf("Convertir '11' en base 1 (no válido): %d\n", ft_atoi_base("11", 1)); // Case not valid
	return (0);
}

/* Solution:
Convertir '120' en base 16 a decimal: 288
Convertir '101' en base 2 a decimal: 5
Convertir '7b' en base 16 a decimal: 123
Convertir '-10' en base 10 a decimal: -10
Convertir 'FF' en base 16 a decimal: 255
Convertir '21' en base 8 a decimal: 17
Convertir 'z' en base 36 (no válido): 0
Convertir '11' en base 1 (no válido): 0 */