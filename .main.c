/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:30:43 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 21:59:17 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		count1;
	int		count2;
	char	*str;
	int		num;
	char	*null_str = NULL;
	void	*null_ptr = NULL;

	str = "Hello, World!";
	num = 42;
	
	printf("\n=== Basic String Test ===\n");
	count1 = ft_printf("Test string: %s\n", str);
	count2 = printf("Test string: %s\n", str);
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
	count1 = ft_printf("Mixed test: %d %s %x %% %p %u %c\n", 42, "test", 255, &num, 42, 'Z');
	count2 = printf("Mixed test: %d %s %x %% %p %u %c\n", 42, "test", 255, &num, 42, 'Z');
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

	printf("=== Edge Cases - Invalid Format Specifiers ===\n");
	count1 = ft_printf("Invalid specifiers: %z %y %w\n");
	count2 = printf("Invalid specifiers: %z %y %w\n");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Edge Cases - Multiple Consecutive %% ===\n");
	count1 = ft_printf("Multiple %%: %%%%%%\n");
	count2 = printf("Multiple %%: %%%%%%\n");
	printf("ft_printf return: %d\n", count1);
	printf("printf return: %d\n\n", count2);

	printf("=== Testing NULL format string ===\n");
	count1 = ft_printf(NULL);
	count2 = printf(NULL);
	fprintf(stderr, "ft_printf(NULL) return: %d\n", count1);
	fprintf(stderr, "printf(NULL) return: %d\n\n", count2);

	printf("=== Testing closed stdout ===\n");
	fclose(stdout);
	fprintf(stderr, "PRINTF: %d\n", printf("teste123\n"));
	fprintf(stderr, "FT_PRINTF: %d\n", ft_printf("teste123\n"));
	
	return (0);
}