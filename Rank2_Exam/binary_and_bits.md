# operaciones a nivel de bit: bitwise operators

You need to use bit-level operations to access each individual bit of the byte. 
The most common operations are: 
AND (&), OR (|), XOR (^), NOT (~), left shift (<<), and right shift (>>).

int z = 0       binary:  0 = 00000000

int x = 6       binary:  6 = 00000110
int y = 12      binary: 12 = 00001100

- AND: 0+0=0    1+0=0    1+1=1
x & y = 4       binary:  4 = 00000100

- OR: 0+0=0    1+0=1    1+1=1
x & y = 14      binary: 14 = 00001110