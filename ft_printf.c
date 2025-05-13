/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:14:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 21:58:03 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), 1));
	if (format == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 0));
	if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	if (format == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_length;
	int		i;

	if (!format)
	 	return (-1);
	if (write(1, "", 0) == -1)
		return (-1);
	print_length = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			print_length += ft_format(args, format[++i]);
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
