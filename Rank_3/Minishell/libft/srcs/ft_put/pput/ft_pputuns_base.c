/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputuns_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mby <mby@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2023/12/11 18:19:40 by mby              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_pputuns_base(void *content, t_cchar *base)
{
	ft_putuns_base(*(t_uns *)content, base);
}

void	ft_pputuns_base_fd(void *content, t_cchar *base, int fd)
{
	ft_putuns_base_fd(*(t_uns *)content, base, fd);
}
