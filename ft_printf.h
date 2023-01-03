/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:31:34 by paugonca          #+#    #+#             */
/*   Updated: 2022/12/26 16:23:24 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

//ft_printf.c
int		ft_printf(const char *type, ...);
//num_and_mem_utils.c
void	putmem(unsigned long int ptr, int *res);
void	puthex(unsigned long int num, const char type, int *res);
char	*unsig_itoa(unsigned int n);
void	putint_n_free(int n, int *res);
void	putunsigint_n_free(unsigned int n, int *res);

#endif
