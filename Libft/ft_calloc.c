/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:57 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 16:26:03 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	x;

	x = nmemb * size;
	if (nmemb != 0 && x / nmemb != size)
		return (NULL);
	else if ((size < 0 && nmemb < 0)
		|| (nmemb < 0 && size > 0) || (nmemb > 0 && size < 0))
		return (NULL);
	else if (nmemb == 0 || size == 0)
	{
		nmemb = size;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
