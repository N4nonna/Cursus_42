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
    unsigned char *idest;
    const unsigned char   *isrc;
    unsigned char   temp[n];
    long unsigned int i;
    
    idest = (unsigned char *)dest;
    isrc = (const unsigned char *)src;
    
    i = 0;
    while (i < n)
    {
        temp[i] = isrc[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        idest[i] = temp[i];
        i++;
    }
    return (dest);
}

int main (void)
{
    unsigned char dest[50] = "BLABLABLA";
    unsigned const char src[50] = "Il fait beau aujourd'hui !";
    
    printf("Original string : %s", src);
    ft_memmove(dest + 9, src, 12);
    printf("\nModified string : %s\n", dest);
    return (0);
}
