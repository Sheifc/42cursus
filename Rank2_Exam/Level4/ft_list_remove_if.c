/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include "ft_list.h" 
#include <stdlib.h>

// Recursividad:

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL) //begin_list = puntero al contenido
        return;

    t_list *current = *begin_list;

    if (cmp(current->data, data_ref) == 0)
    {
        *begin_list = current->next; // Move the head pointer to the next element
        free(current); // Free the currentrent element
        ft_list_remove_if(begin_list, data_ref, cmp); // Recurrentsive call to continue checking
    }
    else
        // The 'else' part handles the case when the current node does not match.
        // It then recurrentsively checks the next node in the list.
        ft_list_remove_if(&current->next, data_ref, cmp);
}
// Modo iterativo:

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *aux;

    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        aux = *begin_list;
        *begin_list = (*begin_list)->next;
        free(aux);
    }
    current = *begin_list;
    while (current && current->next)
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            aux = current->next;
            current->next = aux->next;
            free(aux);
        }
        else
            current = current->next;
    }
}

#include <stdio.h>
#include <string.h>

void	print_list(t_list **begin_list)
{
	t_list *current = *begin_list;
	while (current != 0)
	{
		printf("%s\n", (char*)current->data);
		current = current->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);
}



/* 
To implement the ft_list_remove_if function as described, you'll need to traverse the linked list, 
compare each element's data to the reference data using the cmp function, and remove the elements that match. 
*/

// listas enlazadas: **begin_list es la cabeza de la lista
// begin_list: puntero al puntero de la cabeza de la lista
// *begin_list: se refiere al contenido del primer puntero, es decir, al puntero a la cabeza de la lista

/* 
Modificar begin_list cambiaría la dirección a la que apunta el puntero de la cabeza, 
pero como es un parámetro de función, lo que realmente quieres modificar es el valor en la dirección 
a la que apunta, por eso no modificas begin_list directamente 
 */

/* 
Utilizas *begin_list cuando deseas acceder o modificar el nodo actual al que apunta la cabeza de la lista 
(por ejemplo, para avanzar al siguiente nodo o modificar el valor del nodo actual)
 */

/* 
el doble puntero se utiliza para tener la capacidad de modificar el puntero a la cabeza de la lista 
desde dentro de la función, lo cual es esencial para operaciones que pueden incluir la modificación 
o eliminación del primer elemento de la lista. El uso de begin_list o *begin_list depende de si necesitas 
trabajar con el puntero a la cabeza de la lista en sí o con el contenido (nodos) de la lista.
*/