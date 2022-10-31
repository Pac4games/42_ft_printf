/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:53:59 by paugonca          #+#    #+#             */
/*   Updated: 2022/10/31 14:38:25 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(unsigned long num, int base)
{
	int	p;

	p = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= base;
		p++;
	}
	return (p);
}

char	*ft_itoa_base(unsigned long num, int base)
{
	int		p;
	int		len;
	char	*radix;
	char	*res;

	if (num == 0)
		return (ft_strdup("0"));
	p = 0;
	len = numlen(num, base);
	radix = "0123456789ABCDEF";
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	while (len > 0)
	{
		res[len - 1] = radix[num % base];
		num /= base;
		len--;
	}
	return (res);
}
