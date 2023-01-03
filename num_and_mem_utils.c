/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_and_mem_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:01:49 by paugonca          #+#    #+#             */
/*   Updated: 2023/01/03 14:57:47 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex(unsigned long int num, char type, int *res)
{
	char	*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num < 16)
		ft_putchar(base[num % 16], res);
	else
	{
		puthex(num / 16, type, res);
		puthex(num % 16, type, res);
	}
}

void	putmem(unsigned long int ptr, int *res)
{
	unsigned long int	hold;

	hold = ptr;
	if (hold == 0)
	{
		*res += write(1, "(nil)", 5);
		return ;
	}
	ft_putstr("0x", res);
	puthex(hold, 'x', res);
}

char	*unsig_itoa(unsigned int n)
{
	long	num;
	size_t	len;
	char	*res;

	num = (long)n;
	len = 0;
	if (n == 0)
		return (ft_itoa(n));
	while (n)
	{
		n /= 10;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (0);
	*(res + len--) = '\0';
	while (num > 0)
	{
		*(res + len--) = num % 10 + 48;
		num /= 10;
	}
	if (len == 0 && res[1] == '\0')
		*(res + len) = 48;
	return (res);
}

void	putint_n_free(int n, int *res)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr(num, res);
	free(num);
}

void	putunsigint_n_free(unsigned int n, int *res)
{
	char	*num;

	num = unsig_itoa(n);
	ft_putstr(num, res);
	free(num);
}
