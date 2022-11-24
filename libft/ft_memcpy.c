/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:30:03 by paugonca          #+#    #+#             */
/*   Updated: 2022/10/31 14:31:49 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	p;

	p = 0;
	if (dst == src || len == 0)
		return (dst);
	while (p < len)
	{
		((char *)dst)[p] = ((const char *)src)[p];
		p++;
	}
	return (dst);
}
