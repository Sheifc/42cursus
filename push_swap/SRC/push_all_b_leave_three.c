/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_b_leave_three.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:24:15 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:43:10 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	average(t_node *head)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (head)
	{
		sum += head->index;
		head = head->next;
		i++;
	}
	return (sum / i);
}

void	push_all_b_leave_three(t_node **head_a, t_node **head_b)
{
	int	size;

	size = 0;
	size = ft_stacksize(*head_a);
	while (size > 3)
	{
		if ((*head_a)->index < average(*head_a))
			move_pb(head_a, head_b);
		else
			move_ra(head_a);
		size = ft_stacksize(*head_a);
	}
}
