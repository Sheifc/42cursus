/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:58:15 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 18:59:28 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char c)
{
	if (c < '0' || c > '9')
	{
		printf("Error: Argument must be a number\n");
		return (1);
	}
	return (0);
}

int	check_num(long num)
{
	if (num > 2147483647)
	{
		printf("Error: Argument is too big\n");
		return (1);
	}
	if (num < 0)
	{
		printf("Error: Argument must be positive\n");
		return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (is_number(*str))
		return ((long)-2);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (check_num(num * sign))
		return ((long)-2);
	return (num);
}
