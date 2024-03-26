/* 
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
 */

// version de Rossi: pasa el grademe
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

t_list	*sort_list (t_list *lst, int (*cmp)(int, int))
{
	int	aux;
	t_list	*ptr;

	ptr = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			aux = lst->data;
			lst->data = lst->next->data;
			lst->next->data = aux;
			lst = ptr;
		}
		else
			lst = lst->next;
	}
	lst = ptr;
	return (lst);
}

////////////////////COMPROBACION//////////////

int ascending(int a, int b)
{
	return (a <= b);
}
// Función para añadir un nuevo nodo al inicio de la lista.
t_list *add_to_list(t_list *list, int data)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL; // Comprobación de asignación fallida.

    new_node->data = data;
    new_node->next = list;
    return new_node;
}

// Función para imprimir los elementos de la lista.
void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

// Función para liberar la memoria de la lista.
void free_list(t_list *list)
{
    t_list *tmp;
    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main()
{
    t_list *my_list = NULL;

    // Añadiendo algunos datos a la lista.
    my_list = add_to_list(my_list, 5);
    my_list = add_to_list(my_list, 3);
    my_list = add_to_list(my_list, 8);
    my_list = add_to_list(my_list, 1);
    my_list = add_to_list(my_list, 2);

    // Imprimiendo la lista antes de ordenar.
    printf("Lista antes de ordenar:\n");
    print_list(my_list);

    // Ordenando la lista.
    my_list = sort_list(my_list, ascending);

    // Imprimiendo la lista después de ordenar.
    printf("Lista después de ordenar:\n");
    print_list(my_list);

    // Liberando la memoria de la lista.
    free_list(my_list);

    return 0;
}
