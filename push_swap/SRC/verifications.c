/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:14:17 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:38:47 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_stack(t_stack *stack, int n)
{
	t_node	*aux;

	aux = stack->head;
	while (aux)
	{
		if (aux->data == n)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	is_sorted(t_node *head)
{
	t_node	*aux;

	aux = head;
	while (aux && aux->next)
	{
		if (aux->data > aux->next->data)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	is_empty_or_space_only(const char *str)
{
	if (!str || *str == '\0')
		return (1);
	while (*str) 
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_number_valid(char *str)
{
	if ((*str == '-' || *str == '+') && !ft_isdigit(*(str + 1)))
		show_error();
	if (*str == '-' || *str == '+')
		str++;
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	int_limit(long n)
{
	if (n < INT_MIN || n > INT_MAX)
		show_error();
}
