/* Subject:

Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */

#include <stdio.h>

// By recursivity:

int is_power_of_2(unsigned int n)
{
	if (n == 0) return (0);
	if (n == 1) return (1);
	if (n % 2 == 0)
		return (is_power_of_2(n/2));
	return (0);
}

// To test:
int main(void)
{
	unsigned int n = 12;
	printf("%d", is_power_of_2(n));
	return (0);
}

// By bits:

/* This function will check if the given number is a power of 2 by continuously dividing the number by 2 
(if it's even) and checking if it eventually equals 1. 
Alternatively, it uses the properties of binary numbers to perform a quick check.*/

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n & (n - 1)) == 0;
}
