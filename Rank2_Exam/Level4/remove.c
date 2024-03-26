#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
        return;
	t_list *current = *begin_list;

	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		*begin_list = current->next;
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
}

void	print_list(t_list **begin_list)
{
	t_list *current = *begin_list;
	while (current != 0)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *a = malloc(sizeof(t_list));
	a->next = 0;
	a->data = straa;

	char strbb[] = "String bb";
	t_list *b = malloc(sizeof(t_list));
	b->next = 0;
	b->data = strbb;

	char strcc[] = "String cc";
	t_list *c = malloc(sizeof(t_list));
	c->next = 0;
	c->data = strcc;

	char strdd[] = "String dd";
	t_list *d = malloc(sizeof(t_list));
	d->next = 0;
	d->data = strdd;

	a->next = b;
	b->next = c;
	c->next = d;

	t_list **begin_list = &a;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);
}
