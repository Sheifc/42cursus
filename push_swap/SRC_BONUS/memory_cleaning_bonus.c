/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaning_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:17:05 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:41 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_clean_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

void	ft_clean_both_error(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack)
{
	t_node	*aux;
	t_node	*temp;

	aux = stack->head;
	while (aux != NULL)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
	}
	stack->head = NULL;
}

void	show_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
