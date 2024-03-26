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

/* Un byte tiene 8 bits. Revertir los bits significa que el bit en la posición 0 se intercambia con el bit en la posición 7, 
el bit en la posición 1 con el bit en la posición 6, y así sucesivamente. 
En otras palabras, el orden de los bits se invierte por completo.

Inicializar un Resultado: Comienza con un nuevo byte llamado resultado, inicializado en 0. 
Este byte almacenará el resultado final después de invertir los bits.

Iterar sobre cada Bit: Necesitarás un bucle que recorra cada bit del byte original. 
Puedes hacer esto 8 veces, una para cada bit.

Extraer cada Bit: Dentro del bucle, debes extraer el bit en la posición actual. 
Esto se hace mediante la operación AND entre el byte original y una máscara que tenga un 1 solo en la posición del bit 
que deseas extraer. Por ejemplo, si quieres extraer el bit en la posición 0, usas la máscara 1 (que es 00000001 en binario). 
Si es la posición 1, usas la máscara 2 (00000010), y así sucesivamente. Esto se hace generalmente desplazando el 1 
a la posición correcta usando el operador de desplazamiento a la izquierda (<<).

Posicionar el Bit en su Nueva Ubicación: Después de extraer el bit, necesitas colocarlo en su nueva posición en el byte resultado. 
Esto se hace usando el operador de desplazamiento a la izquierda (<<). El número de posiciones que necesitas desplazar 
varía según la posición del bit. Por ejemplo, el bit en la posición 0 (el menos significativo) se desplaza 7 posiciones 
a la izquierda, y el bit en la posición 1 se desplaza 6 posiciones, y así sucesivamente.

Combinar el Bit con el Resultado: Usa el operador OR (|) para combinar este bit recién posicionado con el resultado. 
Esto "añade" el bit en su nueva posición.

Repetir para Todos los Bits: Repite este proceso para cada uno de los 8 bits.

Resultado Final: Después de procesar todos los bits, resultado contendrá la versión invertida del byte original. */

#include <stdio.h>
#include <unistd.h>

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

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char reverted = 0;
    unsigned char bit;
    int i = 0; 
    while (i < 8)
    {   // AND: 0+0=0    1+0=0    1+1=1 // binary: octet = 01000001 1 = 00000001
        bit = (octet >> i) & 1; // Desplaza i posiciones todos los bits del octet a la derecha
        // 1 en binary: 00000001 se usa como mascara para comprobar que bit es el ultimo
		// desplaza los bits de octet i posiciones hacia la derecha para ir comprobando de derecha a izquiera con la mascara
        reverted = reverted | (bit << (7 - i)); // result |= (bit << (7 - i)); 
        // OR: 0+0=0    1+0=1    1+1=1 // 00000000 OR 
        // Desplazar el bit a su nueva posición y añadirlo al resultado
		i++;
    }
    return (reverted);
}

int main(void)
{
    unsigned char reverted = 0;
    unsigned char octet = 65; // 01000001 en binario
    reverted = reverse_bits(octet);
    print_bit(reverted);
    return 0;
}

/* 
bit = (octet >> i) & 1;

Vamos a usar un ejemplo concreto para explicar la línea `bit = (octet >> i) & 1;`. 
Supongamos que `octet` es `01000001` en binario (que es 65 en decimal) y vamos a calcular el valor de `bit` 
para diferentes valores de `i`.

Vamos a ver qué pasa cuando `i = 0` y `i = 1`.

1. **Cuando `i = 0`:**
   - `octet` es `01000001`.
   - `octet >> i` es `octet >> 0`, lo cual significa que no desplazamos `octet` en absoluto 
   (desplazar 0 posiciones es igual a no hacer ningún desplazamiento). Entonces, `octet >> 0` es todavía `01000001`.
   - Ahora aplicamos `& 1`, que es `01000001 & 00000001`. Solo el bit menos significativo (el de más a la derecha) 
   se compara con 1. En este caso, ese bit es 1.
   - El resultado es `00000001`, lo que significa que `bit` será `1`.

2. **Cuando `i = 1`:**
   - `octet` es `01000001`.
   - `octet >> i` es `octet >> 1`, lo cual significa que desplazamos todos los bits de `octet` una posición 
   hacia la derecha. El resultado es `00100000`.
   - Ahora aplicamos `& 1`, que es `00100000 & 00000001`. De nuevo, solo el bit menos significativo se compara con 1. 
   En este caso, ese bit es 0.
   - El resultado es `00000000`, lo que significa que `bit` será `0`.

Este proceso se repite para cada valor de `i` de 0 a 7. El resultado final es que `bit` obtendrá el valor de cada bit 
en `octet`, uno por uno, comenzando desde el bit menos significativo (el de más a la derecha) hasta el más significativo 
(el de más a la izquierda). */

/* result |= (bit << (7 - i));

Vamos a explicar la línea `result |= (bit << (7 - i));` 
con un ejemplo concreto, continuando con `octet` como `01000001` y usando los valores de `bit` obtenidos para 
`i = 0` y `i = 1`.

Recordemos que `result` es donde estamos construyendo nuestro byte invertido, y comienza en `00000000`.

1. **Cuando `i = 0` y `bit = 1`:**
   - El valor de `bit` que obtuvimos para `i = 0` fue `1`.
   - `bit << (7 - i)` es `1 << (7 - 0)`, lo cual es `1 << 7`. Esto significa que desplazamos el bit `1` 
   siete posiciones a la izquierda, resultando en `10000000`.
   - Ahora, realizamos `result |= 10000000`. Dado que `result` es `00000000`, el resultado de esta operación 
   será `10000000`. Así, hemos colocado correctamente el bit menos significativo de `octet` en la posición 
   más significativa de `result`.

2. **Cuando `i = 1` y `bit = 0`:**
   - El valor de `bit` que obtuvimos para `i = 1` fue `0`.
   - `bit << (7 - i)` es `0 << (7 - 1)`, lo cual es `0 << 6`. Cualquier número desplazado a la izquierda por `0` 
   sigue siendo `0`, así que el resultado sigue siendo `00000000`.
   - Realizamos `result |= 00000000`. Como `result` actualmente es `10000000`, esta operación no cambia `result`. 
   Sigue siendo `10000000`.

Este proceso se repite para cada valor de `i` de 0 a 7. Cada bit extraído de `octet` se desplaza a su nueva 
posición en `result`. Si el bit es `1`, se agrega a `result` en la posición correspondiente. Si es `0`, 
no cambia el estado actual de `result` en esa posición específica.

Al final del bucle, `result` contendrá la versión invertida de `octet`, donde el bit menos significativo 
de `octet` se convierte en el más significativo de `result`, y así sucesivamente.
 */

/* 
`|=` en C.

El operador `|=` es un operador de asignación compuesto que combina el operador OR bit a bit (`|`) con la asignación (`=`). 
En esencia, `x |= y` es una forma abreviada de escribir `x = x | y`. Veamos cómo funciona esto:

1. **Operador OR bit a bit (`|`)**:
   - Este operador realiza una operación OR bit a bit entre dos números. En una operación OR bit a bit, 
   si alguno de los bits correspondientes de los dos operandos es 1, el bit resultante es 1. Si ambos son 0, 
   el resultado es 0.
   - Por ejemplo, `1010 | 0101` daría como resultado `1111`.

2. **Combinando OR con Asignación (`|=`)**:
   - El operador `|=` toma el resultado de la operación OR bit a bit y lo asigna al operando de la izquierda.
   - Por ejemplo, si tienes `x = 1010` y ejecutas `x |= 0101`, primero se realiza la operación OR, 
   que en este caso resulta en `1111`, y luego este resultado se asigna de nuevo a `x`. Por lo tanto, `x` ahora es `1111`.

En el contexto de tu función `reverse_bits`, `result |= (bit << (7 - i));` 
significa que estás tomando el bit que has extraído y desplazado a su nueva posición, 
realizando una operación OR con el valor actual de `result`, y luego almacenando el resultado de nuevo en `result`. 
Esto tiene el efecto de "colocar" el bit en su nueva posición en `result` sin alterar los otros bits que ya has procesado 
en iteraciones anteriores del bucle. */