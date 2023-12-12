/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:03:54 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 09:42:52 by mescoda          ###   ########.fr       */
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

int	is_ber(char *str, char *find)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (find[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == find[y] && str[i + y] && find[y])
			y++;
		if (find[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}
