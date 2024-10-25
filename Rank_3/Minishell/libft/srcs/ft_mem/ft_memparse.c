/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:58:27 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 11:48:01 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(t_cvoid *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	c = (t_uchar)c;
	while (i < n)
	{
		if (((t_uchar *)(s))[i] == c)
			return (&((t_uchar *)(s))[i]);
		i++;
	}
	return (0);
}

void	*ft_memrchr(t_cvoid *s, int c, size_t n)
{
	size_t	i;

	i = n;
	c = (t_uchar)c;
	while (i)
	{
		if (((t_uchar *)(s))[i - 1] == c)
			return (&((t_uchar *)(s))[i - 1]);
		i--;
	}
	return (0);
}

void	*ft_memmem(t_cvoid *h, size_t hl, t_cvoid *n, size_t nl)
{
	size_t	i;

	i = 0;
	if (!h || !n)
		return (NULL);
	while (i < hl - nl)
	{
		if (ft_memcmp(n, &((t_uchar *)h)[i], nl))
			return (&((t_uchar *)h)[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(t_cvoid *s1, t_cvoid *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((t_uchar *)s1)[i] != ((t_uchar *)s2)[i])
			return (((t_uchar *)s1)[i] - ((t_uchar *)s2)[i]);
		i++;
	}
	return (0);
}
