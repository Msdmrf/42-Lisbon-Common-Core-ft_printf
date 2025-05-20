/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:14:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/20 12:10:35 by migusant         ###   ########.fr       */
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

	if (!format || write(1, "", 0) == -1)
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

/* #include <gnu/libc-version.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	main(void)
{
	int		count1;
	int		count2;
	int		num;
	char	*str;
	char	*null_str = NULL;
	void	*null_ptr = NULL;

	str = "Hello, World!";
	num = 42;
	
	printf("\nGNU libc version: %s\n", gnu_get_libc_version());
	
	printf("\n=== Basic Tests ===\n");
	count1 = ft_printf("Test string: %s\n", str);
	count2 = printf("Test string: %s\n", str);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	count1 = ft_printf("Character: %c\n", 'A');
	count2 = printf("Character: %c\n", 'A');
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	
	printf("String test:\n");
	count1 = ft_printf("String: %s\n", "test");
	count2 = printf("String: %s\n", "test");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	
	printf("Pointer test:\n");
	count1 = ft_printf("Pointer: %p\n", &num);
	count2 = printf("Pointer: %p\n", &num);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	
	printf("Integer test:\n");
	count1 = ft_printf("Integer: %d or %i\n", num, num);
	count2 = printf("Integer: %d or %i\n", num, num);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	
	printf("Unsigned test:\n");
	count1 = ft_printf("Unsigned: %u\n", 4294967295);
	count2 = printf("Unsigned: %u\n", 4294967295);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	
	printf("Hexadecimal test:\n");
	count1 = ft_printf("Hexadecimal: %x or %X\n", 255, 255);
	count2 = printf("Hexadecimal: %x or %X\n", 255, 255);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	
	printf("Percent sign test:\n");
	count1 = ft_printf("Percent sign: %%\n");
	count2 = printf("Percent sign: %%\n");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);
	

	printf("=== Edge Cases - NULL Values ===\n");
	printf("NULL string:\n");
	count1 = ft_printf("NULL string test: %s.\n", null_str);
	count2 = printf("NULL string test: %s.\n", null_str);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("NULL pointer:\n");
	count1 = ft_printf("NULL pointer test: %p\n", null_ptr);
	count2 = printf("NULL pointer test: %p\n", null_ptr);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Numbers ===\n");
	printf("INT_MAX:\n");
	count1 = ft_printf("INT_MAX: %d\n", INT_MAX);
	count2 = printf("INT_MAX: %d\n", INT_MAX);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("INT_MIN:\n");
	count1 = ft_printf("INT_MIN: %d\n", INT_MIN);
	count2 = printf("INT_MIN: %d\n", INT_MIN);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("UINT_MAX:\n");
	count1 = ft_printf("UINT_MAX: %u\n", UINT_MAX);
	count2 = printf("UINT_MAX: %u\n", UINT_MAX);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Mixed Format Specifiers ===\n");
	count1 = ft_printf("Mixed test: %d %s %x %% %p %u %c\n", 
		42, "test", 255, &num, 42, 'Z');
	count2 = printf("Mixed test: %d %s %x %% %p %u %c\n", 
		42, "test", 255, &num, 42, 'Z');
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	//	Reserved letters in printf:
  //		Format specifiers: c, s, p, d, i, u, x, X, n, f, e, E, g, G, a, A, o
  //		Length modifiers: h, l, j, z, t, L
	//		No special meaning in printf: b, k, m, q, r, v, w, y 
	
	printf("=== Edge Cases - Invalid Format Specifiers ===\n");
	count1 = ft_printf("Invalid specifiers: %v %w %y\n");
	count2 = printf("Invalid specifiers: %v %w %y\n");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Empty Strings ===\n");
	count1 = ft_printf("");
	count2 = printf("");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Only Format Specifier ===\n");
	count1 = ft_printf("%%");
	count2 = printf("%%");
	printf("\nft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Multiple Consecutive %% ===\n");
	count1 = ft_printf("Multiple %%: %%%%%%\n");
	count2 = printf("Multiple %%: %%%%%%\n");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Pointer Arithmetic ===\n");
	int a = 42;
	int *ptr = &a;
	int **ptr_to_ptr = &ptr;
	count1 = ft_printf("Basic pointer: %p\n", ptr);
	count2 = printf("Basic pointer: %p\n", ptr);
	count1 = ft_printf("Pointer arithmetic: %p\n", ptr + 1);
	count2 = printf("Pointer arithmetic: %p\n", ptr + 1);
	count1 = ft_printf("Double pointer: %p\n", ptr_to_ptr);
	count2 = printf("Double pointer: %p\n\n", ptr_to_ptr);

	printf("=== Edge Cases - Special Characters ===\n");
	count1 = ft_printf("Special chars: \t|\n|\v|\f|\r|\n");
	count2 = printf("Special chars: \t|\n|\v|\f|\r|\n");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Negative Numbers ===\n");
	count1 = ft_printf("Negative hex: %x\n", -42);
	count2 = printf("Negative hex: %x\n", -42);
	count1 = ft_printf("Negative unsigned: %u\n", -42);
	count2 = printf("Negative unsigned: %u\n", -42);
	count1 = ft_printf("Large negative: %d\n", -2147483647);
	count2 = printf("Large negative: %d\n\n", -2147483647);

	printf("=== Edge Cases - Hex Values ===\n");
	count1 = ft_printf("Hex lower: %x\n", 0xabcdef);
	count2 = printf("Hex lower: %x\n", 0xabcdef);
	count1 = ft_printf("Hex upper: %X\n", 0xabcdef);
	count2 = printf("Hex upper: %X\n", 0xabcdef);
	count1 = ft_printf("Hex zero: %x\n", 0);
	count2 = printf("Hex zero: %x\n\n", 0);

	printf("=== Edge Cases - String Edge Cases ===\n");
	char *partial_str = "Hello, World!";
	count1 = ft_printf("Partial string: %s\n", partial_str + 7);
	count2 = printf("Partial string: %s\n", partial_str + 7);
	count1 = ft_printf("Empty string: %s\n", "");
	count2 = printf("Empty string: %s\n\n", "");

	printf("=== Edge Cases - Character Tests ===\n");
	count1 = ft_printf("ASCII char: %c\n", 127);
	count2 = printf("ASCII char: %c\n", 127);
	count1 = ft_printf("Char arithmetic: %c\n", 'a' + 1);
	count2 = printf("Char arithmetic: %c\n\n", 'a' + 1);

	printf("=== Edge Cases - Format String NULL ===\n");
	count1 = ft_printf(NULL);
	count2 = printf(NULL);
	fprintf(stderr, "ft_printf(NULL) return: %d\n", count1);
	fprintf(stderr, "printf(NULL) return: %d\n\n", count2);

	printf("=== Testing closed stdout ===\n");
	fclose(stdout);
	fprintf(stderr, "PRINTF: %d\n", printf("teste123\n"));
	fprintf(stderr, "FT_PRINTF: %d\n\n", ft_printf("teste123\n"));
	
	return (0);
} */