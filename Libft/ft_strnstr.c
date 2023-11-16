/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:15:36 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/16 18:04:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t				i;
	long unsigned int	slen;

	i = 0;
	slen = ft_strlen(little);
	if (slen == 0)
		return ((char *)big);
	while (i < len)
	{
		if (ft_strncmp((char *)&big[i], (char *)little, slen) == 0)
		{
			if (i + slen > len)
				return (NULL);
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
