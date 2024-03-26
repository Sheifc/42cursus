#include <stdio.h>

int ft_atoi_base(const char *str,int str_base)
{
    int i = 0;
    int result = 0;
    int sig = 1;
 
    char *str1 = (char*)str;

    if(str1[i] == '-')
        sig = -1;
    if(str1[i] == '-' || str1[i] == '+')
        i++;
    while((str1[i] != '\0' && ((str1[i] <= '9' && str1[i] >= '0') || \
		(str1[i] >= 'a' && str1[i] <= 'f') || (str1[i] <= 'F' && str1[i] >= 'A'))))
    {
        if(str1[i] <= '9' && str1[i] >= '0' && (str1[i] - '0') >= str_base)
            break;
        if((str1[i] >= 'a' && str1[i] <= 'f' && (str1[i] - 'a' + 10) >= str_base))
            break;
        if(str1[i] <= '9' && str1[i] >= '0' && (str1[i] - '0') < str_base)
        {
            result = result * str_base + str1[i] - '0';
            i++;
        }
        if(str1[i] <= 'F' && str1[i] >= 'A')
            str1[i] = str1[i] + 32;
        if(str1[i] >= 'a' && str1[i] <= 'f' && (str1[i] - 'a' + 10) < str_base)
        {
            result = result * str_base + str1[i] - 'a' + 10;
            i++;
        }
    }
    return(sig * result);
}

int main()
{
    // Pruebas con diferentes strings y bases
    printf("Convertir '120' en base 16 a decimal: %d\n", ft_atoi_base("120", 16));
    printf("Convertir '101' en base 2 a decimal: %d\n", ft_atoi_base("101", 2));
    printf("Convertir '7b' en base 16 a decimal: %d\n", ft_atoi_base("7b", 16));
    printf("Convertir '-10' en base 10 a decimal: %d\n", ft_atoi_base("-10", 10));
    printf("Convertir 'FF' en base 16 a decimal: %d\n", ft_atoi_base("FF", 16));
    printf("Convertir '21' en base 8 a decimal: %d\n", ft_atoi_base("21", 8));
    printf("Convertir 'z' en base 36 (no válido): %d\n", ft_atoi_base("z", 36)); // Caso no válido
    printf("Convertir '11' en base 1 (no válido): %d\n", ft_atoi_base("11", 1)); // Caso no válido
    printf("Convertir '1' en base 2 a decimal: %d\n", ft_atoi_base("1", 2));

    // Prueba en base 10, el máximo dígito es '9'.
    printf("Convertir '9' en base 10 a decimal: %d\n", ft_atoi_base("9", 10));

    // Prueba en base 16, el máximo dígito es 'f'.
    printf("Convertir 'f' en base 16 a decimal: %d\n", ft_atoi_base("f", 16));

    // Prueba en base 16, intentando exceder el máximo dígito con 'g'.
    printf("Convertir 'g' en base 16 a decimal (debe ser inválido): %d\n", ft_atoi_base("g", 16));

    // Prueba en base 10, intentando exceder el máximo dígito con 'a'.
    printf("Convertir 'a' en base 10 a decimal (debe ser inválido): %d\n", ft_atoi_base("a", 10));

    // Prueba con el máximo valor permitido para base 16.
    printf("Convertir 'ff' en base 16 a decimal: %d\n", ft_atoi_base("ff", 16));

    // Prueba con el máximo valor permitido para base 16, incluyendo un valor no permitido 'g'.
    printf("Convertir 'fg' en base 16 a decimal (debe ser inválido): %d\n", ft_atoi_base("fg", 16));
    return 0;
}

/* Solución:
Convertir '120' en base 16 a decimal: 288
Convertir '101' en base 2 a decimal: 5
Convertir '7b' en base 16 a decimal: 123
Convertir '-10' en base 10 a decimal: -10
Convertir 'FF' en base 16 a decimal: 255
Convertir '21' en base 8 a decimal: 17
Convertir 'z' en base 36 (no válido): 0
Convertir '11' en base 1 (no válido): 0 */