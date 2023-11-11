/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:19:42 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 16:14:14 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    int   len;
    size_t i;
    
    if (dest == src)
        return (dest);
    i = 0;
    if (dest < src)
    {
        while (i < n)
        {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    else
    {
        while (i < n)
        {
            len = n - 1 - i;
            ((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
            i++;
        }
    }
    return (dest);
}
