/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:14:08 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:39:03 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target(t_node **head_a, t_node **head_b)
{
	t_node	*aux_b;
	t_node	*aux_a;
	int		target;
	int		max;

	aux_b = *head_b;
	while (aux_b)
	{
		max = INT_MAX;
		aux_a = *head_a;
		while (aux_a)
		{
			if (aux_b->index < aux_a->index && aux_a->index < max)
			{
				target = aux_a->position;
				max = aux_a->index;
			}
			aux_a = aux_a->next;
		}
		if (max == INT_MAX)
			target = lowest_index(&aux_a);
		aux_b->target = target;
		aux_b = aux_b->next;
	}
}
