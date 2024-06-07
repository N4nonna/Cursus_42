/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:26:35 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/16 16:36:16 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (s1 == s2)
		return (0);
	while (n-- > 0)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		if (*us1 == '\0')
			return (0);
		us1++;
		us2++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!s1 || !s2)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (s1 == s2)
		return (0);
	while (*s2)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		if (*us1 == '\0')
			return (0);
		us1++;
		us2++;
	}
	return (0);
}
