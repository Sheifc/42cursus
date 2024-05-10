/* Subject:
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d",mcd(atoi(argv[1]), atoi(argv[2])));
	printf("\n");
    return (0);
}
