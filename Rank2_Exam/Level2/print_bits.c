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

/* Estrategia para imprimir el byte en binario:

Comienza con el bit más significativo (el bit más a la izquierda) y avanza hacia el bit menos significativo (el bit más a la derecha).
Para acceder a cada bit, puedes usar una máscara y la operación AND. 
Una máscara es un byte donde todos los bits son 0, excepto uno que es 1. 
Por ejemplo, para el bit más significativo, la máscara sería 10000000 en binario o 128 en decimal.
Proceso paso a paso:

Inicia con una máscara para el bit más significativo (por ejemplo, 128 o 10000000 en binario).
Aplica la operación AND entre el byte y la máscara. Si el resultado es diferente de 0, 
entonces el bit en esa posición es 1, de lo contrario es 0.
Imprime '1' o '0' según el resultado.
Desplaza la máscara un bit hacia la derecha (usando el desplazamiento a la derecha >>) y repite el proceso para el siguiente bit.
Continúa este proceso hasta que hayas revisado todos los bits (8 veces en total). */

/* La diferencia entre >> 1 y i >>= 1 es cómo se usa cada operador en el contexto de una expresión o asignación en C.

>> 1:

Este es el operador de desplazamiento a la derecha. Cuando usas >> 1, 
estás desplazando los bits de un número una posición hacia la derecha.
Por ejemplo, si tienes a >> 1, significa que tomas el valor de a, 
desplazas sus bits una posición hacia la derecha, y luego usas o evalúas este valor desplazado. 
Sin embargo, el valor original de a no cambia después de esta operación.

i >>= 1:

Este es el operador de asignación de desplazamiento a la derecha. Aquí, 
no solo desplazas los bits de i una posición hacia la derecha, sino que también asignas el nuevo valor a i.
Es equivalente a hacer i = i >> 1. Primero se desplazan los bits de i a la derecha, 
y luego este nuevo valor se guarda en i. Por lo tanto, después de esta operación, el valor de i se actualiza. */

/* La forma if (octet & i) es una forma más concisa y comúnmente usada en C para expresar la misma condición. 
En C, cualquier valor distinto de cero se interpreta como verdadero (true) en un contexto booleano, 
como en una sentencia if. Por lo tanto, si el resultado de octet & i es cualquier valor distinto de cero, 
la condición se evalúa como verdadera.

En cambio, la forma if ((octet & i) != 0) es más explícita y puede ser más fácil de entender para alguien 
que está aprendiendo o para quienes prefieren un estilo de programación que exprese las condiciones 
de manera más detallada. Esta forma compara explícitamente el resultado de octet & i con cero, y si son diferentes, 
la condición se evalúa como verdadera.

En C, cualquier número distinto de cero se considera verdadero (true), y el cero se considera falso (false).

Ambas formas son correctas y equivalen a lo mismo.  */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 128; // Inicializamos i con 128, que es 10000000 en binario y se usará para comparar nuestro número

    while (i)
    {
        if ((octet & i) != 0) // AND: 0+0=0    1+0=0    1+1=1
            write(1, "1", 1); // Si el resultado es diferente de 0, escribimos 1
        else
            write(1, "0", 1); // Si el resultado es 0, escribimos 0
        i = i >> 1; // Desplazamos la máscara un bit a la derecha: i >>= 1;
    }
}

int main()
{
    print_bits(2); // Esto imprimirá 00000010
    return 0;
}
