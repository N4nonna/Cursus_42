/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:26:36 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/09/20 16:21:47 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(t_cchar *big, t_cchar *little)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (!big || !little)
		return (NULL);
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (ft_strlen(big) == 0)
		return (0);
	l = ft_strlen(big) - ft_strlen(little);
	while (i <= l && big[i])
	{
		j = 0;
		while ((char)big[i + j] == (char)little[j])
		{
			j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(t_cchar *big, t_cchar *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (!big || !little)
		return (NULL);
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0 || ft_strlen(big) == 0)
		return (0);
	l = len - ft_strlen(little);
	while (i <= l && big[i])
	{
		j = 0;
		while ((char)big[i + j] == (char)little[j])
		{
			j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
