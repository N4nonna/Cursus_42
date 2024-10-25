/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluns_base2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/27 17:36:42 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ftu_putrslluns_bv(t_lluns n, t_cchar *base, size_t bl);

size_t	ft_putrslluns_base(t_lluns n, t_cchar *base)
{
	int	bl;

	if (!ft_base_valid(base))
		return (0);
	bl = ft_strlen(base);
	return (ftu_putrslluns_bv(n, base, bl));
}

static size_t	ftu_putrslluns_bv(t_lluns n, t_cchar *base, size_t bl)
{
	size_t	ret;

	ret = 0;
	if (n > bl)
	{
		ret += ftu_putrslluns_bv(n / bl, base, bl);
		ret += ftu_putrslluns_bv(n % bl, base, bl);
	}
	else
		return (ft_putrschar(base[n]));
	return (ret);
}

static size_t	ftu_putrslluns_bv_fd(t_lluns n, t_cchar *b, size_t bl, int fd);

size_t	ft_putrslluns_base_fd(t_lluns n, t_cchar *b, int fd)
{
	int	bl;

	if (!ft_base_valid(b))
		return (0);
	bl = ft_strlen(b);
	return (ftu_putrslluns_bv_fd(n, b, bl, fd));
}

static size_t	ftu_putrslluns_bv_fd(t_lluns n, t_cchar *b, size_t bl, int fd)
{
	size_t	ret;

	ret = 0;
	if (n > bl)
	{
		ret += ftu_putrslluns_bv_fd(n / bl, b, bl, fd);
		ret += ftu_putrslluns_bv_fd(n % bl, b, bl, fd);
	}
	else
		return (ret + ft_putrschar_fd(b[n], fd));
	return (ret);
}
