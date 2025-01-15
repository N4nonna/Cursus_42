/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtest1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:58 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 11:01:26 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_cisinstr(t_cchar c, t_cchar *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_csisinstr(t_cchar *set, t_cchar *str)
{
	size_t	i;

	if (!set || !str)
		return (0);
	i = 0;
	while (set[i])
	{
		if (ft_cisinstr(set[i], str))
			return (1);
		i++;
	}
	return (0);
}

int	ft_cisainstr(t_cchar c, t_cchar *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_csisainstr(t_cchar *set, t_cchar *str)
{
	size_t	i;

	if (!set || !str)
		return (0);
	i = 0;
	while (set[i])
	{
		if (!ft_cisinstr(set[i], str))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strdoubles(t_cchar *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_cisinstr(str[i], &str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}
