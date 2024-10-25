/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:53:23 by mby               #+#    #+#             */
/*   Updated: 2024/02/26 17:16:24 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputendl(void *content, t_cchar *base)
{
	ft_pputstr(content, base);
	write(1, "\n", 1);
}

void	ft_pputendl_fd(void *content, t_cchar *base, int fd)
{
	ft_pputstr_fd(content, base, fd);
	write(fd, "\n", 1);
}
