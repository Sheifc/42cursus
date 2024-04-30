/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:32:53 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/26 13:12:23 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node **head)
{
	t_node	*aux;

	if (!head || !(*head) || !(*head)->next)
		return ;
	aux = (*head)->next;
	(*head)->next = aux->next;
	aux->next = *head;
	*head = aux;
}

void	swap_ss(t_node **head_a, t_node **head_b)
{
	swap(head_a);
	swap(head_b);
}

void	move_sa(t_node	**head_a)
{
	swap(head_a);
	ft_printf("sa\n");
}

void	move_sb(t_node	**head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	move_ss(t_node	**head_a, t_node **head_b)
{
	swap_ss(head_a, head_b);
	ft_printf("ss\n");
}
