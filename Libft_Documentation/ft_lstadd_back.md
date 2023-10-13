# ft_lstadd_back_bonus function:

Add the node 'new' to the end of the linked list 'lst'.

# Implementation:

```c
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL; // This is not accepted by francinette tests
	}
}
````
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		lst = new;
	else 
	{
		last->next = new;
		new->next = NULL; // This is not accepted by francinette tests
	}
}
