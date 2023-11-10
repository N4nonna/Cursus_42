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
    unsigned char *idest;
    const unsigned char   *isrc;
    
    idest = (unsigned char *)dest;
    isrc = (const unsigned char *)src;
    while (n-- > 0)
        *idest++ = *isrc++;
    return (dest);
}
