/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:27:06 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:27:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(unsigned char c, unsigned char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i])
	{
		if (c == s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_startlen(unsigned char *str, unsigned char *set)
{
	size_t	i;

	i = 0;
	while (ft_strcmp(str[i], set) == 0)
		i++;
	if (ft_strlen((const char *)str) == i)
		return (0);
	return (i);
}

static size_t	ft_endlen(unsigned char *str, unsigned char *set)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i -= 1;
	while (ft_strcmp(str[i], set) == 0)
		i--;
	return (i - ft_startlen(str, set));
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*trim;
	unsigned char	*uset;
	unsigned char	*us1;
	size_t			i;
	size_t			start;

	if (!s1 || !set)
		return (0);
	uset = (unsigned char *)set;
	us1 = (unsigned char *)s1;
	start = ft_startlen(us1, uset);
	trim = (char *)malloc(sizeof(char) * ((ft_endlen(us1, uset) + 1) + 1));
	if (!trim)
		return (NULL);
	i = 0;
	*trim = 0;
	while (i < ft_endlen(us1, uset) + 1)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
