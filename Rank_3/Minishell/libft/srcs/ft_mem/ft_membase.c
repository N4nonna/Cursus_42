/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_membase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:57:00 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 11:47:10 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, t_cvoid *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!(t_uchar *)dest || !(t_uchar *)src)
		return (NULL);
	while (i < n)
	{
		((t_uchar *)dest)[i] = ((t_uchar *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memccpy(void *dest, t_cvoid *src, int c, size_t n)
{
	t_uns	i;

	i = 0;
	if (!(t_uchar *)dest || !(t_uchar *)src)
		return (NULL);
	while (i < n)
	{
		((t_uchar *)dest)[i] = ((t_uchar *)src)[i];
		if (((t_uchar *)src)[i] == c)
			return (&((t_uchar *)dest)[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, t_cvoid *src, size_t n)
{
	size_t			i;

	if (!n)
		return (dest);
	i = 0;
	n--;
	if ((t_uchar *)src < (t_uchar *)dest)
	{
		while (i <= n)
		{
			((t_uchar *)dest)[n - i] = ((t_uchar *)src)[n - i];
			i++;
		}
	}
	if (((t_uchar *)dest) < ((t_uchar *)src))
	{
		while (i <= n)
		{
			((t_uchar *)dest)[i] = ((t_uchar *)src)[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_uchar *)s)[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
