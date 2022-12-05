/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:05:00 by paugonca          #+#    #+#             */
/*   Updated: 2022/12/05 12:05:16 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adaptaded version to fit the way my ft_printf.c works.
void	ft_putchar(char c, int *res)
{
	*res += write(1, &c, 1);
}
