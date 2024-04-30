/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:43:22 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:37:04 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_position(t_node **head)
{
	t_node	*current;
	int		count;

	if (head == NULL)
		return ;
	current = *head;
	count = 0;
	while (current != NULL)
	{
		current->position = count;
		count++;
		current = current->next;
	}
}
