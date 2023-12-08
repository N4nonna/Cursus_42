/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:03:50 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/08 12:39:25 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_add(char *str, char buff)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	ret[++i] = '\0';
	return (ret);
}

int	gnl(int fd, char **str)
{
	char	buff;
	int		ret;

	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		*str = str_add(*str, buff);
		if (buff == '\n')
			return (ret);
		else
			ret += 1;
		ret = read(fd, &buff, 1);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}