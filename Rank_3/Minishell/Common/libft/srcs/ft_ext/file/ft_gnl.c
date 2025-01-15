/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:42:29 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 18:12:13 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_gnl(int fd)
{
	return (get_next_line(fd));
}

char	*ft_gnl_mf(int fd)
{
	return (get_next_line_mf(fd));
}

int	ft_gnla(int fd, char **addr)
{
	if (!addr)
		return (0);
	*addr = get_next_line(fd);
	if (*addr)
		return (1);
	return (0);
}

int	ft_gnla_mf(int fd, char **addr)
{
	if (!addr)
		return (0);
	*addr = get_next_line_mf(fd);
	if (*addr)
		return (1);
	return (0);
}
