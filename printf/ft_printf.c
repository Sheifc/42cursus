/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:01:43 by sheferna          #+#    #+#             */
/*   Updated: 2023/10/31 14:03:40 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char format, va_list ap)
{
	int			i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		i += ft_putptr(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		i += ft_putnbrbase((long)va_arg(ap, int), 10, \
		"0123456789");
	else if (format == 'u')
		i += ft_putnbrbase((long)va_arg(ap, unsigned int), 10, \
		"0123456789");
	else if (format == 'x')
		i += ft_putnbrbase((long)va_arg(ap, unsigned int), 16, \
		"0123456789abcdef");
	else if (format == 'X')
		i += ft_putnbrbase((long)va_arg(ap, unsigned int), 16, \
		"0123456789ABCDEF");
	else
		i += ft_putchar(format);
	return (i);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			i += ft_print_format(*(++format), ap);
		else
			i += ft_putchar(format);
		++format;
	}
	va_end(ap);
	return (i);
}


