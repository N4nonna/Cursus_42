/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:16:06 by mby               #+#    #+#             */
/*   Updated: 2024/03/13 11:08:37 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_intnoverflow(t_cchar *str)
{
	size_t	i;
	int		nd;

	if (!str)
		return (0);
	i = ft_indexnstr_set(str, "\f\n\r\t\v ");
	if (str[i] == '-')
	{
		i++;
		nd = ft_indexnstr_set(&str[i], "0123456789");
		if (nd == -1)
			nd = ft_strlen(&str[i]);
		if (nd < 10 || (nd == 10 && ft_strncmp(&str[i], "2147483648", nd) <= 0))
			return (1);
		return (0);
	}
	if (str[i] == '+')
		i++;
	nd = ft_indexnstr_set(&str[i], "0123456789");
	if (nd == -1)
		nd = ft_strlen(&str[i]);
	if (nd < 10 || (nd == 10 && ft_strncmp(&str[i], "2147483647", nd) <= 0))
		return (1);
	return (0);
}

int	ft_unsnoverflow(t_cchar *str)
{
	size_t	i;
	int		nd;

	if (!str)
		return (0);
	i = ft_indexnstr_set(str, "\f\n\r\t\v ");
	if (str[i] == '+')
		i++;
	nd = ft_indexnstr_set(&str[i], "0123456789");
	if (nd == -1)
		nd = ft_strlen(&str[i]);
	if (nd < 10 || (nd == 10 && ft_strncmp(&str[i], "4294967295", nd) <= 0))
		return (1);
	return (0);
}
