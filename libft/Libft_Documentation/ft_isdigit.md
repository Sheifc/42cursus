# ft_isdigit function

NAME: isdigit, isnumber – decimal-digit character test
LIBRARY: Standard C Library (libc, -lc)
SYNOPSIS
     #include <ctype.h>
     int isdigit(int c);
     int isnumber(int c);

DESCRIPTION: The isdigit() function tests for a decimal digit character. 

# Implementation

```c
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/* 
int	main(void)
{
	printf("%i", ft_isdigit('0'));
	printf("%i", isdigit('i'));
} */
```