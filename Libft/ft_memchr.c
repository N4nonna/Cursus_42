/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:21:37 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 16:34:54 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    const char *ptr;
    
    ptr = (const char *)s;
    while (n-- > 0)
    { 
        if (*ptr == c)
            return ((void *)ptr);
        ptr ++;
    }
    return (0);
}

/*int main (void)
{
    const unsigned char s[50] = "Il fait beau aujourd'hui !";
    char *ret;
    ret = ft_memchr(s, 'z', 40);
    printf("%s --> %s", s, ret);
    return (0);
}*/