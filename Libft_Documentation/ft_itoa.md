# ft_itoa function:

Function Name: ft_itoa

Prototype
```c
char *ft_itoa(int n);
```

Files to Submit: -

Parameters
- `n`: The integer to convert.

Return Value
- The string representing the number.
- NULL if memory allocation fails.

Authorized Functions
- malloc

Description: Using malloc(3), generate a string that represents the integer value received as an argument. Negative numbers must be handled.

# Implementation: 

My implementation: 
```c
static int	ft_length(long n)
{
	int	len;

	len = 1;
/*  	if (n == 0)
		return (1); */
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
```
The function `ft_length` is designed to return the number of digits in a given integer `n`. The variable `len` is initialized to 1 instead of 0 because the function takes into account that even a single-digit number will have a "length" of at least 1.

Here's a breakdown of what the function does:

1. `len` is initialized to 1, assuming at least one digit will be there.
2. If the number `n` is negative, `len` is incremented by 1 to account for the negative sign.
3. The `while` loop continues to divide `n` by 10 as long as `n > 9`, incrementing `len` each time.

This way, `len` will correctly represent the number of characters needed to represent `n`, including any sign character for negative numbers.

For example:

- For `n = 123`, `len` will be 3.
- For `n = -123`, `len` will be 4 (one extra for the negative sign).
- For `n = 9`, `len` will be 1.
- For `n = 0`, `len` will also be 1.

So initializing `len` to 1 makes sense in this context, as it helps in covering the cases mentioned.

```c
char	*ft_itoa(int n)
{
	char			*p;
	int	len;
	long			nbr;

	nbr = (long)n;
	len = ft_length(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	if (nbr == 0)
		p[0] = '0';
	if (nbr < 0)
	{
		p[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		p[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr > 0)
		p[--len] = nbr + '0'; // es --len xq los arrays empiezan en cero y len me da la longitud total del string, hay que disminuir 1 x ej hola me daria 4 de size y al empezar en cero tendriamos q restar 1 para estar en la ultima posición
	p[len] = '\0';
	return (p);
}

/* #include <stdio.h>

int main(void)
{
	char *res = ft_itoa(-9);
	printf("%s", res);
	free(res);
} */

	/* if (n == -2147483648)
	{
		p[0] = '-';
		p[1] = '2';
		n = 147483648;
 	}*/
```