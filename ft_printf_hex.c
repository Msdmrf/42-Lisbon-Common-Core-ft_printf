/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:31:21 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 13:23:15 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex((unsigned long)ptr, 'x');
	return (len);
}
