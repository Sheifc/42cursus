/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:44:10 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:39:56 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_node *head)
{
	int	size;

	if (head == NULL)
		return (0);
	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
