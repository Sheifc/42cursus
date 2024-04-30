/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_aux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:42:07 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/26 09:42:35 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a_aux(t_node **head_a, t_node **head_b)
{
	(void)head_b;
	rotate(head_a);
}

void	rotate_b_aux(t_node **head_a, t_node **head_b)
{
	(void)head_a;
	rotate(head_b);
}

void	reverse_a_aux(t_node **head_a, t_node **head_b)
{
	(void)head_b;
	reverse(head_a);
}

void	reverse_b_aux(t_node **head_a, t_node **head_b)
{
	(void)head_a;
	reverse(head_b);
}
