/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:45:14 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:43 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	n;

	if (!nmemb || !size)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb || (nmemb * size) / nmemb != size)
		return (NULL);
	n = nmemb * size;
	dest = malloc(n);
	if (!dest)
		return (NULL);
	ft_bzero(dest, n);
	return (dest);
}

void	**ft_freeparr(void **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && arr[i])
	{
		free(arr[i]);
		i++;
	}
	return (arr);
}

char	**ft_freestrarr(char **arr, size_t n)
{
	size_t	i;

	if (!arr)
		return (arr);
	i = 0;
	while (i < n && arr[i])
	{
		free(arr[i]);
		i++;
	}
	return (arr);
}
