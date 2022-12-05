/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:46 by paugonca          #+#    #+#             */
/*   Updated: 2022/12/05 13:04:35 by paugonca         ###   ########.fr       */
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
		putmem(va_arg(args, unsigned long int), res);
	else if (type == 'd' || type == 'i')
		ft_putstr(ft_itoa(va_arg(args, int)), res);
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
	void	*p = (void *)s;
	int		i = 69420;

	printf("Original printf:\nPercentage: %%\nChar: %c\nStr: %s\n", c, s);
	printf("Void ptr: %p\nInt: %d or %i\n", p, i, i);
	ft_printf("\nMy ft_printf:\nPercentage: %%\nChar: %c\nStr: %s\n", c, s);
	ft_printf("Void ptr: %p\nInt: %d or %i\n", p, i, i);
	return (0);
}
*/
