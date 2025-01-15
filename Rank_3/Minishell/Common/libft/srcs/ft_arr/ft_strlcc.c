/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:22:15 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/01 12:22:23 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, t_cchar *src, size_t size)
{
	unsigned int	i;

	if (!src || !dst)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		if (i < size)
		{
			dst[i] = '\0';
		}
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, t_cchar *src, size_t size)
{
	unsigned int	i;
	int				j;
	size_t			len_dst;
	size_t			len_src;

	if (!src || !dst)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		return (len_src + size);
	i = len_dst;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (len_dst + len_src);
}
