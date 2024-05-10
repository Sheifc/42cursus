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

// To test:

int main()
{
    t_list *head;
    t_list *node1;
    t_list *node2;
    t_list *node3;

    node1 = (t_list *)malloc(sizeof(t_list));
    node2 = (t_list *)malloc(sizeof(t_list));
    node3 = (t_list *)malloc(sizeof(t_list));

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printf("Size of the list: %d\n", ft_list_size(head));
    free(node1);
    free(node2);
    free(node3);
    return (0);
}

