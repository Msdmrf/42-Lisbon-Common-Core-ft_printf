/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:30:43 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 22:31:35 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	
	printf("\n=== Basic Tests ===\n");
	count1 = ft_printf("Test string: %s\n", str);
	count2 = printf("Test string: %s\n", str);
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	ft_printf("Different formats:\n");
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "test");
	ft_printf("Pointer: %p\n", &num);
	ft_printf("Integer: %d or %i\n", num, num);
	ft_printf("Unsigned: %u\n", 4294967295);
	ft_printf("Hexadecimal: %x or %X\n", 255, 255);
	ft_printf("Percent sign: %%\n\n");

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
}