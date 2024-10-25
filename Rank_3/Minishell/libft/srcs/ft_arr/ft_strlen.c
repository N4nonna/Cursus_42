/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:22:10 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:18 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen(t_cchar *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!str[i + 1])
			return (i + 1);
		if (!str[i + 2])
			return (i + 2);
		if (!str[i + 3])
			return (i + 3);
		if (!str[i + 4])
			return (i + 4);
		if (!str[i + 5])
			return (i + 5);
		i += 6;
	}
	return (i);
}

size_t	ft_strlen_arr(t_cchar **arrstr, size_t n)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	while (i < n && arrstr[i])
	{
		ret += ft_strlen(arrstr[i]);
		i++;
	}
	return (ret);
}

size_t	ft_strnlen(t_cchar *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
	{
		i++;
	}
	return (i);
}
