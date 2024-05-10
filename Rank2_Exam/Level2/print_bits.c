/* Subject:
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010" */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 128;

	while(i)
	{
		if ((octet & i) != 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1;
	}
}

// To test:
int main()
{
    print_bits(2); // It will print 00000010
    return (0);
}
