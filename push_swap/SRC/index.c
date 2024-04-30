/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:56:30 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:35:04 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node **head)
{
	t_node	*aux;
	t_node	*temp;
	int		count;

	if (head == NULL)
		return ;
	aux = *head;
	while (aux)
	{
		count = 1;
		temp = *head;
		while (temp)
		{
			if (temp->data < aux->data)
				count++;
			temp = temp->next;
		}
		aux->index = count;
		aux = aux->next;
	}
}

int	lowest_index(t_node **head)
{
	int		lowest;
	t_node	*aux;
	t_node	*temp;

	if (head == NULL || *head == NULL)
		return (0);
	lowest = INT_MAX;
	aux = *head;
	temp = NULL;
	while (aux != NULL)
	{
		if (aux->index < lowest)
		{
			lowest = aux->index;
			temp = aux;
		}
		aux = aux->next;
	}
	return (temp->position);
}
