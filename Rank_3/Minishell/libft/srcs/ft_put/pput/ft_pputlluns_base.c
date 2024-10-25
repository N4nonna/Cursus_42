/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputlluns_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 17:14:04 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputlluns_base(void *content, t_cchar *base)
{
	ft_putlluns_base(*(t_lluns *)content, base);
}

void	ft_pputlluns_base_fd(void *content, t_cchar *base, int fd)
{
	ft_putlluns_base_fd(*(t_lluns *)content, base, fd);
}
