/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbrll_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:57 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputnbrll_base(void *content, t_cchar *base)
{
	ft_putnbrll_base(*(t_llint *)content, base);
}

void	ft_pputnbrll_base_fd(void *content, t_cchar *base, int fd)
{
	ft_putnbrll_base_fd(*(t_llint *)content, base, fd);
}
