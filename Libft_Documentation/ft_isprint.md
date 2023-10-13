# ft_isprint function:

ISPRINT(3) Library Functions                                                                           

NAME: isprint – printing character test (space character inclusive)

LIBRARY: Standard C Library (libc, -lc)

SYNOPSIS
     #include <ctype.h>
     int isprint(int c);

DESCRIPTION: The isprint() function tests for any printing character, including space (‘ ’).  The value of the argument must be representable as an unsigned char or the value of EOF.

# Implementation

```c
int	ft_isprint(int c)
{
	c = (unsigned char)c;
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isprint(127));
	printf("%i", isprint(127));
} */