/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:28:00 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 17:32:20 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_putnbr(int n);
int			ft_putnbr_base(unsigned int n, char c, char *base);
int			ft_printstr(char *str);
int			ft_printch(char c);
int			ft_printpercent(void);
int			ft_printpoint(unsigned long long ptr);

#endif
