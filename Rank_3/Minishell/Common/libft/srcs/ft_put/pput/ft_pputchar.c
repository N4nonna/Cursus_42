/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:07 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:49 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputchar(void *content, t_cchar *base)
{
	(void)base;
	ft_putchar(*(char *)content);
}

void	ft_pputchar_fd(void *content, t_cchar *base, int fd)
{
	(void)base;
	ft_putchar_fd(*(char *)content, fd);
}
