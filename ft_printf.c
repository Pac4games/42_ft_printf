/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:46 by paugonca          #+#    #+#             */
/*   Updated: 2023/01/04 16:36:56 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	exec_flag(va_list args, const char type, int *res)
{
	if (type == '%')
		ft_putchar('%', res);
	else if (type == 'c')
		ft_putchar(va_arg(args, int), res);
	else if (type == 's')
		ft_putstr(va_arg(args, char *), res);
	else if (type == 'p')
		putmem(va_arg(args, unsigned long int), res);
	else if (type == 'd' || type == 'i')
		putint_n_free(va_arg(args, int), res);
	else if (type == 'u')
		putunsigint_n_free(va_arg(args, unsigned int), res);
	else if (type == 'x' || type == 'X')
		puthex(va_arg(args, unsigned int), type, res);
}

static void	exec_bonus_flag(const char bonus, const char type, int *res)
{
	if (bonus == '#' && type == 'x')
		ft_putstr("0x", res);
	else if (bonus == '#' && type == 'X')
		ft_putstr("0X", res);
}

int	ft_printf(const char *type, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, type);
	while (*type)
	{
		if (*type == '%')
		{
			type++;
			if (*type == '#')
			{
				ft_printf("[Cardinal detected]");
				exec_bonus_flag(*type, *type + 1, &res);
				type++;
			}
			exec_flag(args, *type, &res);
		}
		else
			ft_putchar(*type, &res);
		type++;
	}
	va_end(args);
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char			c = 'c';
	char			s[] = "This is a test string."; 
	void			*p = (void *)s;
	int				i = 12345;
	unsigned int	u = 4294967295;
	unsigned int	x = 42;
	unsigned int	X = 42;

	printf("Original printf:\n\nPercentage: %%\nChar: %c\nStr: %s\n", c, s);
	printf("Void ptr: %p\nInt: %d or %i\nUnsig int: %u\n", p, i, i, u);
	printf("'x' conversion: %x\n'X' conversion: %X\n", x, X);
	printf("'#x' conversion: %#x\n'#X' conversion: %#X\n", x, X);
	ft_printf("---------------------------------------------");
	ft_printf("\nMy ft_printf:\n\nPercentage: %%\nChar: %c\nStr: %s\n", c, s);
	ft_printf("Void ptr: %p\nInt: %d or %i\nUnsig int: %u\n", p, i, i, u);
	ft_printf("'x' conversion: %x\n'X' conversion: %X\n", x, X);
	ft_printf("'#x' conversion: %#x\n'#X' conversion: %#X\n", x, X);
	return (0);
}
