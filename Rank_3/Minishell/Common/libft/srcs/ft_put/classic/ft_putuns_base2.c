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

static size_t	ftu_putrsuns_bv(t_uns n, t_cchar *base, size_t bl);

size_t	ft_putrsuns_base(t_uns n, t_cchar *base)
{
	int	bl;

	if (!ft_base_valid(base))
		return (0);
	bl = ft_strlen(base);
	return (ftu_putrsuns_bv(n, base, bl));
}

static size_t	ftu_putrsuns_bv(t_uns n, t_cchar *base, size_t bl)
{
	size_t	ret;

	ret = 0;
	if (n > bl)
	{
		ret += ftu_putrsuns_bv(n / bl, base, bl);
		ret += ftu_putrsuns_bv(n % bl, base, bl);
	}
	else
		return (ret + ft_putrschar(base[n]));
	return (ret);
}

static size_t	ftu_putrsuns_bv_fd(t_uns n, t_cchar *base, size_t bl, int fd);

size_t	ft_putrsuns_base_fd(t_uns n, t_cchar *base, int fd)
{
	int	bl;

	if (!ft_base_valid(base))
		return (0);
	bl = ft_strlen(base);
	return (ftu_putrsuns_bv_fd(n, base, bl, fd));
}

static size_t	ftu_putrsuns_bv_fd(t_uns n, t_cchar *base, size_t bl, int fd)
{
	size_t	ret;

	ret = 0;
	if (n > bl)
	{
		ret += ftu_putrsuns_bv_fd(n / bl, base, bl, fd);
		ret += ftu_putrsuns_bv_fd(n % bl, base, bl, fd);
	}
	else
		return (ret + ft_putrschar_fd(base[n], fd));
	return (ret);
}
