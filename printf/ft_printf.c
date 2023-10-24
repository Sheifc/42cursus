/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:01:43 by sheferna          #+#    #+#             */
/*   Updated: 2023/10/22 21:30:22 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list ap)
{
	int			count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		count += ft_putnbrbase((long)va_arg(ap, int), 10, \
		"0123456789");
	else if (format == 'u')
		count += ft_putnbrbase((long)va_arg(ap, unsigned int), 10, \
		"0123456789");
	else if (format == 'x')
		count += ft_putnbrbase((long)va_arg(ap, unsigned int), 16, \
		"0123456789abcdef");
	else if (format == 'X')
		count += ft_putnbrbase((long)va_arg(ap, unsigned int), 16, \
		"0123456789ABCDEF");
	else
		count += write(1, &format, 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
/* 
int	main(void)
{
	int	count;

	count = ft_printf("Hello %s\n", "Sheila");
	ft_printf("The chars written are %d\n", count);
	count = ft_printf("%x\n", 42);
	ft_printf("The chars written are %d\n", count);
	count = ft_printf("Hello %s\n", "John");

	printf("%d chars\n", count);//, fflush(stdout);
	count = ft_printf("Char-> %c\n", 'a');
	printf("%d chars\n", count);//, fflush(stdout);
	count = ft_printf("Nbr-> %d\n", -42);
	printf("%d chars\n", count);//, fflush(stdout);
	count = ft_printf("Hex-> %x\n", -1);
	printf("%d chars\n", count);//, fflush(stdout);

} */
