/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:52:58 by paugonca          #+#    #+#             */
/*   Updated: 2022/11/30 16:25:28 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_error(char *str)
{
	int	p;
	int	i;

	p = 0;
	if (str[0] == '\0' || ft_strlen(str) == 1)
		return (0);
	while (str[p] != '\0')
	{
		if (str[p] <= 32 || str[p] == 127 || str[p] == '+' || str[p] == '-')
			return (0);
		i = p + 1;
		while (i < ft_strlen(str))
		{
			if (str[p] == str[i])
				return (0);
			i++;
		}
		p++;
	}
	return (1);
}

void	ft_putnbr_base(int n, char *base, int *res)
{
	int			len;
	int			error;
	long int	num;

	error = check_error(base);
	len = ft_strlen(base);
	num = n;
	if (error == 1)
	{
		if (num < 0)
		{
			ft_putchar('-', *res);
			num *= -1;
		}
		if (num < len)
			ft_putchar(base[num], *res);
		if (num >= len)
		{
			ft_putnbr_base(num / len, base, *res);
			ft_putnbr_base(num % len, base, *res);
		}	
	}
}
