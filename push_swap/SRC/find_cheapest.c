/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:21:06 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/25 12:58:28 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int cost)
{
	if (cost < 0)
		cost = cost * (-1);
	return (cost);
}

t_node	*find_cheapest_node(t_node **head_b)
{
	t_node	*current;
	t_node	*cheapest;

	current = *head_b;
	cheapest = *head_b;
	while (current)
	{
		if (ft_abs(current->cost_a) + ft_abs(current->cost_b)
			< ft_abs(cheapest->cost_a) + ft_abs(cheapest->cost_b))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
