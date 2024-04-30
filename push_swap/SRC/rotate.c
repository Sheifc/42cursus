/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:31:27 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:40:53 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
    (*head)->prev = NULL;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	rotate_rr(t_node **head_a, t_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	move_ra(t_node **head_a)
{
	rotate(head_a);
	ft_printf("ra\n");
}

void	move_rb(t_node **head_b)
{
	rotate(head_b);
	ft_printf("rb\n");
}

void	move_rr(t_node **head_a, t_node **head_b)
{
	rotate_rr(head_a, head_b);
	ft_printf("rr\n");
}
