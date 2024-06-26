/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:26:01 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:26:03 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t maxlen)
{
	char	*p;

	p = ft_memchr(s, 0, maxlen);
	if (p == NULL)
		return (maxlen);
	else
		return (p - s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, size);
	if (dstlen == size)
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_memcpy((dst + dstlen), src, (srclen + 1));
	else
	{
		ft_memcpy((dst + dstlen), src, (size - dstlen - 1));
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
