/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:54:12 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 15:01:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	tab_len(char *tab, char *sep)
{
	int	len;

	len = (ft_strlen(tab) - 1) + ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (tab_len(s1, s2)));
	if (!dest)
		return (NULL);
	*dest = 0;
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
