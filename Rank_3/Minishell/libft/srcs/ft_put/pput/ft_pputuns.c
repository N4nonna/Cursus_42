/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputuns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/26 17:22:44 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputuns(void *content, t_cchar *base)
{
	(void)base;
	ft_putuns(*(t_uns *)content);
}

void	ft_pputuns_fd(void *content, t_cchar *base, int fd)
{
	(void)base;
	ft_putuns_fd(*(t_uns *)content, fd);
}
