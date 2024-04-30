/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:36:49 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/26 13:15:08 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse(t_node **head)
{
	t_node	*last;
	t_node	*penultimate;

	if (!*head || !(*head)->next)
		return ;
	penultimate = NULL;
	last = *head;
	while (last->next != NULL) 
	{
		penultimate = last;
		last = last->next;
	}
	if (penultimate != NULL) 
	{
		penultimate->next = NULL;
		last->prev = NULL;
		last->next = *head;
		(*head)->prev = last;
		*head = last;
	}
}

void	reverse_rrr(t_node **head_a, t_node **head_b)
{
	reverse(head_a);
	reverse(head_b);
}

void	move_rra(t_node **head_a)
{
	reverse(head_a);
	ft_printf("rra\n");
}

void	move_rrb(t_node **head_b)
{
	reverse(head_b);
	ft_printf("rrb\n");
}

void	move_rrr(t_node **head_a, t_node **head_b)
{
	reverse_rrr(head_a, head_b);
	ft_printf("rrr\n");
}
