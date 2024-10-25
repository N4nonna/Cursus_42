/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:28:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:14:15 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputstr(void *content, t_cchar *base)
{
	(void)base;
	ft_putstr((char *)content);
}

void	ft_pputstr_fd(void *content, t_cchar *base, int fd)
{
	(void)base;
	ft_putstr_fd((char *)content, fd);
}
