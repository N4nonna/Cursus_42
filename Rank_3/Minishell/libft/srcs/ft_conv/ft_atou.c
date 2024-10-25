/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:34:04 by mby               #+#    #+#             */
/*   Updated: 2024/03/06 14:43:46 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_uns	ft_atou(t_cchar *str)
{
	size_t	i;
	t_uns	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

t_uns	ft_atou_base(t_cchar *str, t_cchar *base)
{
	size_t	i;
	t_uns	res;
	int		base_size;

	if (!str || !base)
		return (0);
	if (!ft_base_valid(base))
		return (0);
	i = 0;
	base_size = ft_strlen(base);
	res = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_cisinstr(str[i], base))
	{
		res = res * base_size + ft_indexstr(base, str[i]);
		i++;
	}
	return (res);
}

t_lluns	ft_atollu(t_cchar *str)
{
	size_t	i;
	t_lluns	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

t_lluns	ft_atollu_base(t_cchar *str, t_cchar *base)
{
	size_t	i;
	t_lluns	res;
	int		base_size;

	if (!str || !base)
		return (0);
	if (!ft_base_valid(base))
		return (0);
	i = 0;
	base_size = ft_strlen(base);
	res = 0;
	while (ft_cisinstr((int)str[i], SPACES))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_cisinstr(str[i], base))
	{
		res = res * base_size + ft_indexstr(base, str[i]);
		i++;
	}
	return (res);
}
