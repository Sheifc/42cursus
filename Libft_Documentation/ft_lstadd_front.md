# ft_lstadd_front function:

The `ft_lstadd_front` function is designed to add a new node to the front of a singly-linked list. 

# Implementation:

```c
void ft_lstadd_front(t_list **lst, t_list *new)
{
    new -> next = *lst;  // Set the 'next' pointer of the new node to point to the current head of the list.
    lst[0] = new;      // Update the 'lst' pointer to point to the new node, making it the new head of the list.
}
```

Here's a step-by-step explanation of what this code does:

1. The function `ft_lstadd_front` takes two arguments:
   - `t_list **lst`: A pointer to a pointer to the head of the linked list. This pointer is passed by reference because we want to modify the original head pointer.
   - `t_list *new`: A pointer to the new node that you want to add to the front of the list.

2. It sets the `next` pointer of the `new` node to point to the current head of the list. This effectively makes the `new` node the new first element of the list, and it connects the `new` node to the rest of the list.

3. It updates the `lst` pointer (the head pointer) to point to the `new` node. This is important because you want the head of the list to now be the `new` node.

In summary, this function inserts a new node at the front of a linked list. It adjusts the `next` pointers of the new node and the previous head of the list and updates the head pointer itself to point to the new node, making it the new first element of the list.