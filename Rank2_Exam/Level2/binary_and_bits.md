# operaciones a nivel de bit: bitwise operators

Necesitas usar operaciones a nivel de bit para acceder a cada bit individual del byte. 
Las operaciones más comunes son AND (&), OR (|), XOR (^), NOT (~), 
desplazamiento a la izquierda (<<) y desplazamiento a la derecha (>>).

int z = 0       binary:  0 = 00000000

int x = 6       binary:  6 = 00000110
int y = 12      binary: 12 = 00001100

- AND: 0+0=0    1+0=0    1+1=1
x & y = 4       binary:  4 = 00000100

- OR: 0+0=0    1+0=1    1+1=1
x & y = 14      binary: 14 = 00001110