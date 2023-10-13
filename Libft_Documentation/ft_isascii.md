# ft_isascii function

NAME: isascii – test for ASCII character
LIBRARY: Standard C Library (libc, -lc)
SYNOPSIS
     #include <ctype.h>
     int isascii(int c);

DESCRIPTION: The isascii() function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive. Between 0 and 127 both included. 

# Implementation 

```c
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isascii(127));
	printf("%i", ft_isascii(127));
} */
```
