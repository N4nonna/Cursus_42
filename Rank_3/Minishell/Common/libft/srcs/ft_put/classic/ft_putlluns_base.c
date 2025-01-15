/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluns_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/27 17:16:33 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putlluns_bv(t_lluns n, t_cchar *base, size_t bl);

void	ft_putlluns_base(t_lluns n, t_cchar *base)
{
	int	bl;

	if (!ft_base_valid(base))
		return ;
	bl = ft_strlen(base);
	ft_putlluns_bv(n, base, bl);
}

static void	ft_putlluns_bv(t_lluns n, t_cchar *base, size_t bl)
{
	if (n > bl)
	{
		ft_putlluns_bv(n / bl, base, bl);
		ft_putlluns_bv(n % bl, base, bl);
	}
	else
		ft_putchar(base[n]);
}

static void	ft_putlluns_base_v_fd(t_lluns n, t_cchar *b, size_t bl, int fd);

void	ft_putlluns_base_fd(t_lluns n, t_cchar *b, int fd)
{
	int	bl;

	if (!ft_base_valid(b))
		return ;
	bl = ft_strlen(b);
	ft_putlluns_base_v_fd(n, b, bl, fd);
}

static void	ft_putlluns_base_v_fd(t_lluns n, t_cchar *b, size_t bl, int fd)
{
	if (n > bl)
	{
		ft_putlluns_base_v_fd(n / bl, b, bl, fd);
		ft_putlluns_base_v_fd(n % bl, b, bl, fd);
	}
	else
		ft_putchar_fd(b[n], fd);
}
