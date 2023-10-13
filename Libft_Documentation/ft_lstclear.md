# ft_lstclear function

Function Name: ft_lstclear

Prototype: void ft_lstclear(t_list **lst, void (*del)(void*));

Files to Submit: -

Parameters:
lst: The address of a pointer to a node.
del: A function pointer used to delete the content of a node.
Return Value: None

Authorized Functions: free

Description: Deletes and frees the given 'lst' node and all subsequent nodes connected to it, using the 'del' function and free(3).
At the end, the pointer to the list should be NULL.

# Implementation

2 Versions: 

```c
void ft_lstclear(t_list **lst, void (*del)(void *)) 
{
    t_list *current;
    t_list *next;

	current = *lst; // *current = *lst; it is not allowed to make this comparison because it says an entity tlist cannot be equal to another entity t_list, just removing the * of current, it has been accepted. The cause is explained later. 
    while (current) {
        next = current->next; // Store the next pointer before deleting the current node
        del(current->content); // Call the provided del function to delete the content
        free(current);         // Free the memory of the current node
        current = next;        // Move to the next node
    }
    *lst = NULL; // Set the pointer to the list as NULL to indicate an empty list
}
```
In the assignment `current = *lst;`, `current` does not have an asterisk `*` because it is already declared as a pointer to a `t_list` structure earlier in the code.

When we declare a pointer variable, we use the asterisk `*` to indicate that the variable will hold a memory address. Once declared as a pointer, you don't need to use the `*` again when you assign it a value that is also a pointer. 

So, in the line `current = *lst;`, `*lst` is a pointer to a `t_list` structure, and `current` is also a pointer to a `t_list` structure. The `*` is used when declaring the variable to indicate it's a pointer; when assigning a value of the same pointer type, you don't need to repeat the `*`.

Here's a breakdown:

- `t_list *current;` declares `current` as a pointer to a `t_list` structure.
- `current = *lst;` assigns the value of `*lst` (which is also a pointer to a `t_list` structure) to the `current` pointer. There's no need for an extra `*` here because `current` is already declared as a pointer.

I hope this clarifies the usage of the `*` in this context.

Second version: 

```c
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst) -> next;
		del((*lst) -> content);
		free((*lst));
		*lst = next;
	}
	*lst = NULL;
}
```
