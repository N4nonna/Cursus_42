/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbrll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:54 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputnbrll(void *content, t_cchar *base)
{
	(void)base;
	ft_putnbrll(*(t_llint *)content);
}

void	ft_pputnbrll_fd(void *content, t_cchar *base, int fd)
{
	(void)base;
	ft_putnbrll_fd(*(t_llint *)content, fd);
}
