/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:56:27 by sheferna          #+#    #+#             */
/*   Updated: 2023/10/22 21:47:14 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

/**
 * @brief Prints what enters as a param.
 * @param *format The pointer.
 * @param ... 
 * @returns An int.
*/
int	ft_print_format(char format, va_list ap);
int	ft_printf(char const *format, ...);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_putptr_pf(unsigned long ptr);
int	ft_putnbrbase_pf(long n, int base, const char *base_digits);
int	ft_putnbrbase_ptr_pf(unsigned long n, int base, const char *base_digits);

#endif
