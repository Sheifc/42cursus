/* Subject:
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

/* 
This function will take a pointer to the first node of the list as its parameter. 
The linked list is defined using the t_list structure, which contains a next pointer 
to the next element in the list and a data pointer to store the value of the element.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int ft_list_size(t_list *begin_list)
{
    int size = 0;

    while (begin_list)
    {
        begin_list = begin_list->next;
		size++;
    }
    return (size);
}

/* Explicación:
Aquí está cómo funciona:

La función inicia un contador size en 0.
Luego, entra en un bucle while que continúa siempre que el puntero begin_list no sea NULL, 
es decir, mientras haya nodos en la lista.
Dentro del bucle, el puntero begin_list se actualiza para apuntar al siguiente nodo en la 
lista (begin_list = begin_list->next). Esto es esencial para avanzar a través de la lista.
Para cada iteración del bucle, el contador size se incrementa en 1.
Cuando begin_list llega al final de la lista (cuando begin_list es NULL), el bucle termina, 
y la función retorna el valor de size, que es el número total de nodos en la lista.
La confusión podría surgir al pensar que modificar el puntero begin_list dentro de la función 
podría afectar el puntero original que se pasó a la función. Sin embargo, en C, 
los parámetros de funciones son pasados por valor. Esto significa que la función trabaja 
con una copia del puntero, no con el puntero original. Modificar begin_list dentro de la 
función solo cambia la copia local del puntero, no el puntero fuera de la función. 
Por lo tanto, el comportamiento que describes (actualizar begin_list para apuntar al 
siguiente nodo y aumentar size) es precisamente lo que se espera y es correcto para contar 
los elementos de la lista. 

 */
/* 
In this implementation, the ft_list_size function starts with a size of 0. 
It then iterates through each element of the list, incrementing size until 
it reaches the end of the list (where begin_list becomes NULL). 
Finally, it returns the size of the list. */

/* Este main creará una lista enlazada de forma manual, agregando algunos nodos 
y luego usará ft_list_size para verificar que el tamaño reportado sea el correcto. */

int main()
{
    t_list *head;
    t_list *node1;
    t_list *node2;
    t_list *node3;

    // Crear nodos
    node1 = (t_list *)malloc(sizeof(t_list));
    node2 = (t_list *)malloc(sizeof(t_list));
    node3 = (t_list *)malloc(sizeof(t_list));

    // Enlazar nodos
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL; // El último nodo apunta a NULL

    // Probar ft_list_size
    printf("Size of the list: %d\n", ft_list_size(head));

    // Liberar memoria
    free(node1);
    free(node2);
    free(node3);

    return (0);
}

/* Solución:
Size of the list: 3 */

// probar el caso de lista vacia:
/* int main()
{
    t_list *head = NULL; // Inicializar la lista como vacía

    // Probar ft_list_size con una lista vacía
    printf("Size of the list: %d\n", ft_list_size(head));

    return (0);
} */

