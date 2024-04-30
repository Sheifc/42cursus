/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 08:46:14 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:39:49 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	sorting_algorithm(t_node **head_a, t_node **head_b)
{
	push_all_b_leave_three(head_a, head_b);
	sort_three(head_a);
	move_the_rest(head_a, head_b);
}
