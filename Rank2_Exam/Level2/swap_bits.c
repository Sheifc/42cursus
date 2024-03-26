/* ```
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
```
 */

unsigned char swap_bits(unsigned char octet)
{
	return(octet >> 4 | octet << 4) & 0xFF;
}

/* Subject:
La función swap_bits toma un octeto (un número de 8 bits) y cambia de lugar los 4 bits superiores 
con los 4 bits inferiores. Aquí está el detalle de cada paso en la función:

Toma un Octeto: Imagina que el octeto (un byte) es una serie de 8 bits, algo así como 10110010. 
Los 4 bits de la izquierda son 1011 y los 4 de la derecha son 0010.

Desplazamiento a la Derecha (octet >> 4):

Cuando haces octet >> 4, estás moviendo todos los bits 4 posiciones a la derecha.
Por ejemplo, si tienes 10110010 y haces octet >> 4, obtienes 00001011. 
Los 4 bits de la derecha (0010) se han movido hacia la derecha y ahora están en la posición de los 4 bits 
más a la izquierda, mientras que los 4 bits más a la izquierda originalmente (1011) se han "caído" del número 
y los espacios vacíos se llenan con ceros.

Desplazamiento a la Izquierda (octet << 4):

De forma similar, octet << 4 mueve todos los bits 4 posiciones a la izquierda.
Usando el mismo octeto original (10110010), al hacer octet << 4, obtienes 00100000. 
Los 4 bits de la izquierda (1011) se han movido a la izquierda y ahora están en la posición de los 4 bits 
más a la derecha, mientras que los espacios vacíos se llenan con ceros.
Combinación de Ambos Resultados con OR (|):

Luego usas el operador OR (|) para combinar los resultados de los dos desplazamientos.
Si combinas 00001011 (resultado de octet >> 4) y 00100000 (resultado de octet << 4), obtienes 00101011.
El OR compara cada bit de los dos números: si al menos uno de los bits en una posición es 1, 
entonces el bit resultante en esa posición también es 1. Si ambos son 0, el resultado es 0.
Resultado:

El resultado final es un octeto donde los 4 bits que originalmente estaban a la derecha ahora 
están a la izquierda, y viceversa.
En nuestro ejemplo, el octeto original 10110010 se transforma en 00101011.
Esencialmente, lo que hace la función es tomar un octeto, cortarlo por la mitad y luego intercambiar esas dos mitades. 
El uso de los desplazamientos asegura que cada mitad se mueva a su nueva posición, 
y el OR combina estas dos mitades en el resultado final. */

/* En este contexto particular, la operación `& 0xFF` no es estrictamente necesaria,
 pero es una buena práctica en algunos casos, especialmente cuando se trabaja con manipulación de bits. 
 Aquí te explico por qué:

1. **Asegurar el Rango del Resultado**:
   - `0xFF` es 255 en decimal y `11111111` en binario. Al hacer una operación AND (`&`) con `0xFF`, 
   estás asegurando que el resultado no exceda el rango de un `unsigned char` (que es de 0 a 255).
   - Cada bit en el resultado final se compara con el bit correspondiente en `0xFF`. 
   Dado que todos los bits en `0xFF` son 1, el resultado final no cambia (1 AND 1 = 1, 0 AND 1 = 0).

2. **Limpieza de Bits Superiores en Tipos de Datos Mayores**:
   - En algunos contextos, si estuvieras trabajando con tipos de datos que ocupan más de 8 bits 
   (como `int` o `unsigned int` en C), podrías usar `& 0xFF` para asegurarte de que solo los 8 bits 
   inferiores son considerados y todos los bits superiores son descartados (establecidos en 0).
   - Sin embargo, en el caso de `unsigned char`, que está garantizado por el estándar de C que sea de 8 bits,
    esta operación es más una cuestión de claridad o precaución, en caso de que el código cambie en el futuro 
    o el resultado de la operación de bits anterior sea inesperado por alguna razón.

3. **Claridad y Mantenimiento del Código**:
   - Aunque en este caso particular, el resultado de `(octet >> 4) | (octet << 4)` nunca excederá 8 bits, 
   usar `& 0xFF` puede hacer que el propósito del código sea más claro para alguien que lo lea, 
   indicando que el resultado intencionado debe estar dentro del rango de un `unsigned char`.
   - También es una forma de autoprotección contra cambios futuros en el código que puedan introducir resultados inesperados.

Resumiendo, aunque `& 0xFF` no cambia el resultado en este contexto específico, es una práctica útil 
en general para la manipulación de bits, especialmente cuando el tamaño del tipo de dato no está estrictamente definido 
o cuando se quiere enfatizar que solo se están considerando los 8 bits inferiores. */