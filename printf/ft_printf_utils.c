/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:36:34 by sheferna          #+#    #+#             */
/*   Updated: 2023/10/31 15:17:56 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int i = write(1, &c, 1);
	if (i == -1)
		return (-1);
	else
		return (i);
}

int	ft_putstr(char *str)
{
	int	i = 0;
	int res; 

	if (!str)
		str = "(null)";
	while (*str)
		i += ft_putchar(*str++);	 
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	int		i;

	i = 0;
	i += ft_putstr("0x");
	if (ptr == 0)
		i += ft_putchar('0');
	else
		i += ft_putnbrbase_ptr(ptr, 16, "0123456789abcdef");
	return (i);
}

int	ft_putnbrbase_ptr_pf(unsigned long n, int base, const char *base_digits)
{
	int	i;

	if (n < (unsigned long) base)
		return (ft_putchar(base_digits[n]));
	else
	{
		i = ft_putnbrbase_ptr(n / base, base, base_digits);
		return (i + ft_putnbrbase_ptr(n % base, base, base_digits));
	}
}

int	ft_putnbrbase_pf(long n, int base, const char *base_digits)
{
	int	i;

	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbrbase(-n, base, base_digits) + 1);
	}
	if (n < base)
		return (ft_putchar(base_digits[n]));
	else
	{
		i = ft_putnbrbase(n / base, base, base_digits);
		return (i + ft_putnbrbase(n % base, base, base_digits));
	}
}
