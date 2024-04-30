/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:13:45 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/24 17:11:46 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static int	highest_index(t_node *head)
{
	int		highest;

	highest = head->index;
	while (head)
	{
		if (head->index > highest)
			highest = head->index;
		head = head->next;
	}
	return (highest);
}

void	sort_three(t_node **head)
{
	int		highest;

	if (is_sorted(*head))
		return ;
	highest = highest_index(*head);
	if ((*head)->index == highest)
		move_ra(head);
	else if ((*head)->next->index == highest)
		move_rra(head);
	if ((*head)->index > (*head)->next->index)
		move_sa(head);
}
