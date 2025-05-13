/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:31:46 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 22:45:00 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int n, int is_signed)
{
	int	len;

	len = 0;
	if (is_signed && (int)n < 0)
	{
		if ((int)n == -2147483648)
			return (ft_putstr("-2147483648"));
		len += ft_putchar('-');
		n = -(int)n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10, 0);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_puthex(unsigned long n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	if (format == 'x')
		len += ft_putchar("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex(ptr, 'x');
	return (len);
}
