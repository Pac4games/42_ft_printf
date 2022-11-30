/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:46 by paugonca          #+#    #+#             */
/*   Updated: 2022/11/30 16:25:40 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	exec_flag(va_list args, const char type, int *res)
{
	if (type == '%')
		ft_putchar('%', res);
	else if (type == 'c')
		ft_putchar(va_arg(args, int), res);
	else if (type == 's')
		ft_putstr(va_arg(args, char *), res);
	else if (type == 'p')
		ft_putnbr_base(va_arg(args, unsigned long int), res);
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
			exec_flag(args, *type, &res);
		}
		else
			ft_putchar(*type, &res);
		type++;
	}
	va_end(args);
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c = 'c';
	char	s[] = "O Eduardo e um banananao"; 

	printf("Original printf: %%, %c, %s\n", c, s);
	ft_printf("My ft_printf: %%, %c, %s\n", c, s);
	return (0);
}
*/
