/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:58 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputnbr(void *content, t_cchar *base)
{
	(void)base;
	ft_putnbr(*(int *)content);
}

void	ft_pputnbr_fd(void *content, t_cchar *base, int fd)
{
	(void)base;
	ft_putnbr_fd(*(int *)content, fd);
}
