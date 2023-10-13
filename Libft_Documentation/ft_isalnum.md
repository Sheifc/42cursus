# ft_isalnum function

NAME: isalnum – alphanumeric character test
LIBRARY: Standard C Library (libc, -lc)
SYNOPSIS
     #include <ctype.h>
     int isalnum(int c);

DESCRIPTION: The isalnum() function tests for any character for which isalpha(3) or isdigit(3) is true. The value of the argument must be representable as an unsigned char or the value of EOF.

# Implementation

```c
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isalnum(' '));
	printf("%i", ft_isalnum(32));
} */
```
