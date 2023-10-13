# Data types in C:

En el lenguaje de programación C, existen varios formatos de datos que se utilizan para representar diferentes tipos de información. Algunos de los formatos de datos más comunes en C incluyen:

1. **int**: Representa números enteros, positivos o negativos.

2. **float**: Representa números de punto flotante de precisión simple (coma flotante).

3. **double**: Representa números de punto flotante de doble precisión (doble coma flotante).

4. **char**: Representa caracteres individuales, como letras o símbolos.

5. **short**: Representa números enteros cortos, generalmente de menor rango que `int`.

6. **long**: Representa números enteros largos, generalmente de mayor rango que `int`.

7. **unsigned**: Modificador que se puede aplicar a tipos numéricos (como `int`, `short`, `char`, etc.) para indicar que los valores siempre son no negativos.

8. **long long**: Representa números enteros largos con una mayor capacidad de representación.

9. **unsigned int, unsigned char, etc.**: Versiones sin signo de los tipos numéricos mencionados anteriormente.

10. **enum**: Enumeraciones, que permiten definir un conjunto de valores enteros nombrados.

11. **struct**: Estructuras, que permiten combinar múltiples tipos de datos en una sola entidad.

12. **union**: Uniones, que permiten almacenar diferentes tipos de datos en la misma área de memoria.

13. **pointer**: Tipos de datos que almacenan direcciones de memoria.

14. **void**: Un tipo especial que se utiliza para representar la falta de tipo o la ausencia de valor.

15. **Array**: Tipos que representan colecciones de elementos del mismo tipo.

16. **Tipo definido por el usuario**: Los programadores pueden definir sus propios tipos de datos utilizando la palabra clave `typedef`.

Estos son algunos de los tipos de datos más comunes en C, pero el lenguaje ofrece flexibilidad para definir tipos de datos personalizados y combinar tipos básicos para crear estructuras de datos más complejas según las necesidades del programa. Además, los sistemas y compiladores pueden tener tamaños específicos para estos tipos de datos, lo que puede variar entre diferentes sistemas y arquitecturas.

En el lenguaje de programación C, tanto `%d` como `%i` se utilizan en la función `printf` para formatear y mostrar valores enteros en la salida estándar (generalmente la pantalla). Ambos especificadores de formato `%d` y `%i` funcionan de la misma manera y, en la práctica, no hay diferencia en cómo se comportan. Puedes usar cualquiera de los dos indistintamente para imprimir valores enteros, y el resultado será el mismo.

La razón de tener dos especificadores de formato para números enteros (`%d` y `%i`) se debe a la historia del lenguaje C y su flexibilidad en la sintaxis. Ambos hacen exactamente lo mismo: toman un número entero y lo imprimen en el formato especificado en la cadena de formato. La diferencia real radica en cómo se pueden utilizar en contextos más generales.

La especificación `%i` permite un uso más amplio en cuanto a formato. Si precedes el número con "0x", `%i` interpretará el número como un valor en notación hexadecimal. Por ejemplo:

```c
int x = 255;
printf("%i\n", x);    // Imprime 255
printf("%i\n", 0xFF); // Imprime 255 también
```

Mientras que `%d` no interpreta números con "0x" como valores hexadecimales y los considera decimales. Por lo tanto:

```c
int x = 255;
printf("%d\n", x);    // Imprime 255
printf("%d\n", 0xFF); // Imprime 255 como decimal, no interpreta el 0x
```

En resumen, `%d` y `%i` son intercambiables cuando se trata de imprimir números enteros en formato decimal. La diferencia principal es que `%i` permite una interpretación más amplia de formatos, especialmente cuando se trata de valores hexadecimales.

La función `printf` en C utiliza especificadores de formato para controlar cómo se formatea y muestra la salida en la pantalla o en otro destino, como un archivo. A continuación, se presentan algunos de los especificadores de formato más comunes utilizados en `printf`:

1. **%d** o **%i**: Muestra un número entero con signo (decimal).

2. **%u**: Muestra un número entero sin signo (decimal).

3. **%o**: Muestra un número entero en base octal.

4. **%x** o **%X**: Muestra un número entero en base hexadecimal (minúsculas o mayúsculas).

5. **%f**: Muestra un número de punto flotante (coma flotante) en notación decimal.

6. **%e** o **%E**: Muestra un número de punto flotante en notación científica (exponencial).

7. **%g** o **%G**: Muestra un número de punto flotante en notación decimal o científica, según sea más corto.

8. **%c**: Muestra un carácter individual.

9. **%s**: Muestra una cadena de caracteres (string).

10. **%p**: Muestra un puntero en formato hexadecimal.

11. **%%**: Muestra el símbolo de porcentaje literal ("%").

12. **%n**: No muestra ningún valor, pero almacena el número de caracteres escritos hasta ese punto en una variable proporcionada como argumento adicional. Útil para contar la longitud de la cadena generada.

Estos son los especificadores de formato más utilizados en `printf`, pero hay otros más especializados y opciones de formato que se pueden utilizar para controlar la alineación, el ancho del campo, la precisión decimal y otros aspectos del formateo. Además, es posible combinar varios especificadores de formato en una sola llamada a `printf` para formatear y mostrar múltiples valores en una cadena de salida.

Aquí hay un ejemplo simple que utiliza algunos de estos especificadores de formato:

```c
int numero = 42;
double decimal = 3.14159;
char letra = 'A';
printf("Número entero: %d\n", numero);
printf("Número de punto flotante: %f\n", decimal);
printf("Carácter: %c\n", letra);
```

Este código imprimirá:

```
Número entero: 42
Número de punto flotante: 3.141590
Carácter: A
```

[20:16, 26/09/2023] Priscila 42 DWeb: usar unsigned char *p para asignarle un valor void *s
[20:16, 26/09/2023] Priscila 42 DWeb: cuando tienes que usar en argumento, un size_t
[20:17, 26/09/2023] Priscila 42 DWeb: porque el size_t es valor positivo unicamente
[20:17, 26/09/2023] Priscila 42 DWeb: y aparte, marca cada byte de memoria

unsigned char : cada byte de memoria, sin signo, mide 8 bits siempre. Para no preocuparse por el tipo de dato original y se interpreta exacto