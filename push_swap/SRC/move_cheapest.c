/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:57:20 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/25 18:17:00 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	move_cheapest_a(t_node **head_a, t_node *cheapest)
{
	while (cheapest->cost_a > 0)
	{
		move_ra(head_a);
		(cheapest->cost_a)--;
	}
	while (cheapest->cost_a < 0)
	{
		move_rra(head_a);
		(cheapest->cost_a)++;
	}
}

static void	move_cheapest_b(t_node **head_b, t_node *cheapest)
{
	while (cheapest->cost_b > 0)
	{
		move_rb(head_b);
		(cheapest->cost_b)--;
	}
	while (cheapest->cost_b < 0)
	{
		move_rrb(head_b);
		(cheapest->cost_b)++;
	}
}

void	move_cheapest(t_node **head_a, t_node **head_b)
{
	t_node	*cheapest;

	cheapest = find_cheapest_node(head_b);

	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		move_rrr(head_a, head_b);
		(cheapest->cost_a)++;
		(cheapest->cost_b)++;
	}
	while ((cheapest->cost_a > 0) && (cheapest->cost_b > 0))
	{
		move_rr(head_a, head_b);
		(cheapest->cost_a)--;
		(cheapest->cost_b)--;
	}
	move_cheapest_a(head_a, cheapest);
	move_cheapest_b(head_b, cheapest);
	move_pa(head_b, head_a);
}
