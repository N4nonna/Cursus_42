/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:03:54 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/08 13:20:37 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_error(char *error_mess)
{
	ft_printf("%s\n", error_mess);
	return (NULL);
}

char	**ft_free(t_data *data)
{
	map_free(data);
	return (NULL);
}

int	is_ber(const char *str)
{
	char	*s;

	s = ".ber";
	while (*str && *str != *s)
		str++;
	if (*str == *s)
		return (1);
	return (0);
}
