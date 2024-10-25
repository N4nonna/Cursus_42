/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:14:00 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputnbr_base(void *content, t_cchar *base)
{
	ft_putnbr_base(*(int *)content, base);
}

void	ft_pputnbr_base_fd(void *content, t_cchar *base, int fd)
{
	ft_putnbr_base_fd(*(int *)content, base, fd);
}
