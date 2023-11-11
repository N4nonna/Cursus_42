/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:35:56 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 14:48:02 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    if (dest == src)
        return (dest);
    i = 0;
    while (i < n)
    {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        i++;
    }
    return (dest);
}
