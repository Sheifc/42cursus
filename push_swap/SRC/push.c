/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:29:39 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:42:34 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **head_a, t_node **head_b)
{
	t_node	*aux;

	if (!head_a || !(*head_a) || !head_b)
		return ;
	aux = (*head_a)->next;
	(*head_a)->next = *head_b;
	if (*head_b != NULL)
		(*head_b)->prev = *head_a;
	*head_b = *head_a;
	*head_a = aux;
	if (aux != NULL)
		aux->prev = NULL;
	if (*head_b != NULL)
		(*head_b)->prev = NULL;
}

void	move_pb(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
	ft_printf("pb\n");
}

void	move_pa(t_node **head_b, t_node **head_a)
{
	push(head_b, head_a);
	ft_printf("pa\n");
}
