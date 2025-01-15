/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputlluns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:14:02 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputlluns(void *content, t_cchar *base)
{
	(void)base;
	ft_putlluns(*(t_lluns *)content);
}

void	ft_pputlluns_fd(void *content, t_cchar *base, int fd)
{
	(void)base;
	ft_putlluns_fd(*(t_lluns *)content, fd);
}
