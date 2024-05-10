/* Subject:
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b); */

#include <stdio.h>

unsigned int mcd(unsigned int a, unsigned int b)
{
    unsigned int x = 0;
    unsigned int y = 0;

    if (a > b)
        (x = a) && (y = b);
    else
        (x = b) && (y = a);
    if (y == 0)
        return (x);
    else
        return (mcd(y, x % y));
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if ((a == 0) || (b == 0))
        return (0);
    else
        return ((a * b)/ mcd(a, b));
}

// To test:
int main(void)
{
    unsigned int a = 6, b = 4;
    printf("LCM(%u, %u) = %u\n", a, b, lcm(a, b));
    return (0);
}

// Solution: 12
