/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:42:56 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/27 16:26:44 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(sizeof(char) * (len + 1));
	if (!s || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[len] = '\0';
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n-- > 0)
		*ptr++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
