/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:30:43 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 13:22:05 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		count1;
	int		count2;
	char	*str;
	int		num;

	str = "Hello, World!";
	num = 42;
	count1 = ft_printf("Test string: %s\n", str);
	count2 = printf("Test string: %s\n", str);
	ft_printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n", count2);

	ft_printf("Different formats:\n");
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "test");
	ft_printf("Pointer: %p\n", &num);
	ft_printf("Integer: %d or %i\n", num, num);
	ft_printf("Unsigned: %u\n", 4294967295);
	ft_printf("Hexadecimal: %x or %X\n", 255, 255);
	ft_printf("Percent sign: %%\n");

	return (0);
}