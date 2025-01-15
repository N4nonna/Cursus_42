/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:58 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/10 15:28:27 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_lint	ft_indexstr(t_cchar *str, t_cchar c)
{
	t_lint	i;

	if (!str)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexstr_set(t_cchar *str, t_cchar *set)
{
	t_lint	i;

	if (!str || !set)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (ft_cisinstr(str[i], set))
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnstr(t_cchar *str, t_cchar c)
{
	t_lint	i;

	if (!str)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnstr_set(t_cchar *str, t_cchar *set)
{
	t_lint	i;

	if (!str || !set)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (!ft_cisinstr(str[i], set))
			return (i);
		i++;
	}
	return (-1);
}
