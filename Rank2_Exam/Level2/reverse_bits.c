/* Subject: 
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
 */

#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char reverted = 0;
	unsigned char bit;
	int i = 0;

	while (i < 8)
	{
		bit = (octet >> i) & 1;
		reverted |= (bit << (7 - i));
		i++;
	}
	return (reverted);
}

// To test:
void print_bit(unsigned char octet)
{
    int i = 128;

    while (i)
    {
        if ((octet & i) != 0)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i = i >> 1; 
    }
}

int main(void)
{
    unsigned char reverted = 0;
    unsigned char octet = 65; // 01000001 in binary

    reverted = reverse_bits(octet);
    print_bit(reverted);
    return (0);
}
