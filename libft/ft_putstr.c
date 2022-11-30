/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:23:06 by paugonca          #+#    #+#             */
/*   Updated: 2022/11/30 15:32:46 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int *res)
{
	unsigned int	p;

	if (!str)
		ft_putstr("(null)", res);
	else
	{
		p = 0;
		while (str[p])
			ft_putchar(str[p++], res);
	}
}
