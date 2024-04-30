/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:12:22 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:36:55 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_stack *stack, int n)
{
	t_node	*new_node;
	t_node	*last;

	if (is_in_stack(stack, n))
		ft_clean_error(stack);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = n;
	new_node->next = NULL;
	if (stack->head == NULL)
		stack->head = new_node;
	else
	{
		last = stack->head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
}

void	parse_arguments(char **argv, t_stack *stack_a)
{
	int		j;
	long	n;
	char	**numbers;

	j = 0;
	numbers = ft_split(*argv, ' ');
	while (numbers[j] != NULL)
	{
		if (is_number_valid(numbers[j]))
		{
			n = ft_atol(numbers[j]);
			int_limit(n);
			add_to_stack(stack_a, n);
		}
		else
		{
			ft_free_matrix(numbers);
			ft_clean_error(stack_a);
		}
		j++;
	}
	ft_free_matrix(numbers);
}
