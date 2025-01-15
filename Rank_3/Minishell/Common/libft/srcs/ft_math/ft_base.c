/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:04:40 by mby               #+#    #+#             */
/*   Updated: 2024/03/06 14:45:34 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_base_valid(t_cchar *base)
{
	if (!base)
		return (0);
	if (ft_csisinstr(SPACES, base))
		return (0);
	if (ft_strdoubles(base))
		return (0);
	return (1);
}

int	ft_sizeinbase_int(int n, int base_size)
{
	int	ret;

	if (!base_size)
		return (0);
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (ft_sizeinbase_uns((t_uns)INT_MAX + 1, base_size) + 1);
	ret = 0;
	if (n < 0)
		ret += 1;
	ft_tosign(&n, 1);
	while (n != 0)
	{
		n = n / base_size;
		ret += 1;
	}
	return (ret);
}

int	ft_sizeinbase_ll(t_llint n, int base_size)
{
	int	ret;

	if (!base_size)
		return (0);
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (ft_sizeinbase_lluns((t_lluns)LLONG_MAX + 1, base_size) + 1);
	ret = 0;
	if (n < 0)
		ret += 1;
	ft_tosignll(&n, 1);
	while (n != 0)
	{
		n = n / base_size;
		ret += 1;
	}
	return (ret);
}

int	ft_sizeinbase_uns(t_uns n, int base_size)
{
	int	ret;

	if (!base_size)
		return (0);
	if (n == 0)
		return (1);
	ret = 0;
	while (n != 0)
	{
		n = n / base_size;
		ret += 1;
	}
	return (ret);
}

int	ft_sizeinbase_lluns(t_lluns n, int base_size)
{
	int	ret;

	if (!base_size)
		return (0);
	if (n == 0)
		return (1);
	ret = 0;
	while (n != 0)
	{
		n = n / base_size;
		ret += 1;
	}
	return (ret);
}
