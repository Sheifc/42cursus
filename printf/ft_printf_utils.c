/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:36:34 by sheferna          #+#    #+#             */
/*   Updated: 2023/10/22 21:44:48 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int		count;

	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar('0');
	else
		count += ft_putnbrbase_ptr(ptr, 16, "0123456789abcdef");
	return (count);
}

int	ft_putnbrbase(long n, int base, const char *base_digits)
{
	int	count;

	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbrbase(-n, base, base_digits) + 1);
	}
	if (n < base)
		return (ft_putchar(base_digits[n]));
	else
	{
		count = ft_putnbrbase(n / base, base, base_digits);
		return (count + ft_putnbrbase(n % base, base, base_digits));
	}
}

int	ft_putnbrbase_ptr(unsigned long n, int base, const char *base_digits)
{
	int	count;

	if (n < (unsigned long) base)
		return (ft_putchar(base_digits[n]));
	else
	{
		count = ft_putnbrbase_ptr(n / base, base, base_digits);
		return (count + ft_putnbrbase_ptr(n % base, base, base_digits));
	}
}
