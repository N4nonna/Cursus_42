/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:25:52 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:25:55 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = (src)[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	tab_len(char const *tab, char const *sep)
{
	int	len;

	len = (ft_strlen(tab)) + ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (tab_len(s1, s2) + 1));
	if (!dest)
		return (NULL);
	*dest = 0;
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
