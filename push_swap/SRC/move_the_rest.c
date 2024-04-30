/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:24:48 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:36:35 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_node(t_node **head_a)
{
	int	lowest;
	int	size;

	size = ft_stacksize(*head_a);
	assign_position(head_a);
	lowest = lowest_index(head_a);
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			move_rra(head_a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			move_ra(head_a);
			lowest--;
		}
	}
}

void	move_the_rest(t_node **head_a, t_node **head_b)
{
	while (*head_b)
	{
		assign_position(head_a);
		assign_position(head_b);
		assign_target(head_a, head_b);
		assign_cost(head_a, head_b);
		move_cheapest(head_a, head_b);
	}
	if (!is_sorted(*head_a))
		move_node(head_a);
}
