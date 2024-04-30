/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_aux_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:33:45 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:45:14 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a_aux(t_node **head_a, t_node **head_b)
{
	(void)head_b;
	swap(head_a);
}

void	swap_b_aux(t_node **head_a, t_node **head_b)
{
	(void)head_a;
	swap(head_b);
}

void	push_a_aux(t_node **head_a, t_node **head_b)
{
	push(head_b, head_a);
}

void	push_b_aux(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
}
