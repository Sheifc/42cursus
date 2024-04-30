/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:40:53 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:35:26 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_node(t_node **aux, int pos)
{
	int	size;
	int	cost;

	size = ft_stacksize(*aux);
	if (pos > size / 2)
		cost = (size - pos) * (-1);
	else
		cost = pos;
	return (cost);
}

void	assign_cost(t_node **head_a, t_node **head_b)
{
	t_node	*aux_b;

	aux_b = *head_b;
	while (aux_b)
	{
		aux_b->cost_b = cost_node(head_b, aux_b->position);
		aux_b->cost_a = cost_node(head_a, aux_b->target);
		aux_b = aux_b->next;
	}
}
