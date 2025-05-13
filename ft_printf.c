/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:14:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 13:29:58 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length = ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_length = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_length = ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_length = ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length = ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length = ft_putchar('%');
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_length;
	int		i;

	print_length = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{ 
		if (format[i] == '%')
		{
			print_length += ft_format(args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
