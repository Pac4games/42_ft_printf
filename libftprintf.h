/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:31:34 by paugonca          #+#    #+#             */
/*   Updated: 2022/12/05 16:41:12 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *type, ...);
void	putmem(unsigned long int ptr, int *res);
void	puthex(unsigned long int num, const char type, int *res);
char	*unsig_itoa(unsigned int n);

#endif
