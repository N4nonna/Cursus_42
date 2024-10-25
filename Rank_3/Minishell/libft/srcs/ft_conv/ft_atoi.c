/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:11:05 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 14:44:24 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(t_cchar *str)
{
	int		sign;
	size_t	i;
	int		res;

	if (!str)
		return (0);
	sign = 1;
	i = 0;
	res = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '-')
		ft_tosign(&sign, -1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (ft_tosign(&res, sign));
}

int	ft_atoi_base(t_cchar *str, t_cchar *base)
{
	int		sign;
	size_t	i;
	int		res;
	int		base_size;

	if (!str || !base)
		return (0);
	if (!ft_base_valid(base))
		return (0);
	sign = 1;
	res = 0;
	base_size = ft_strlen(base);
	i = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '-')
		ft_tosign(&sign, -1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_cisinstr(str[i], base))
	{
		res = res * base_size + ft_indexstr(base, str[i]);
		i++;
	}
	return (ft_tosign(&res, sign));
}

t_llint	ft_atoll(t_cchar *str)
{
	int		sign;
	size_t	i;
	t_llint	res;

	if (!str)
		return (0);
	sign = 1;
	i = 0;
	res = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '-')
		ft_tosign(&sign, -1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (ft_tosignll(&res, sign));
}

t_llint	ft_atoll_base(t_cchar *str, t_cchar *base)
{
	int		sign;
	size_t	i;
	t_llint	res;
	int		base_size;

	if (!str || !base)
		return (0);
	if (!ft_base_valid(base))
		return (0);
	sign = 1;
	res = 0;
	base_size = ft_strlen(base);
	i = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '-')
		ft_tosign(&sign, -1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_cisinstr(str[i], base))
	{
		res = res * base_size + ft_indexstr(base, str[i]);
		i++;
	}
	return (ft_tosignll(&res, sign));
}
