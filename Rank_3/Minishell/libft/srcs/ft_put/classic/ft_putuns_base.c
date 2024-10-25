/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mby <mby@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2023/12/11 18:19:40 by mby              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putuns_bv(t_uns n, t_cchar *base, size_t bl);

void	ft_putuns_base(t_uns n, t_cchar *base)
{
	int	bl;

	if (!ft_base_valid(base))
		return ;
	bl = ft_strlen(base);
	ft_putuns_bv(n, base, bl);
}

static void	ft_putuns_bv(t_uns n, t_cchar *base, size_t bl)
{
	if (n > bl)
	{
		ft_putuns_bv(n / bl, base, bl);
		ft_putuns_bv(n % bl, base, bl);
	}
	else
		ft_putchar(base[n]);
}

static void	ft_putuns_bv_fd(t_uns n, t_cchar *base, size_t bl, int fd);

void	ft_putuns_base_fd(t_uns n, t_cchar *base, int fd)
{
	int	bl;

	if (!ft_base_valid(base))
		return ;
	bl = ft_strlen(base);
	ft_putuns_bv_fd(n, base, bl, fd);
}

static void	ft_putuns_bv_fd(t_uns n, t_cchar *base, size_t bl, int fd)
{
	if (n > bl)
	{
		ft_putuns_bv_fd(n / bl, base, bl, fd);
		ft_putuns_bv_fd(n % bl, base, bl, fd);
	}
	else
		ft_putchar_fd(base[n], fd);
}
