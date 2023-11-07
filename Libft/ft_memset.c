/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:53:08 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 14:37:41 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <string.h>

void *ft_memset (void *s, int c, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n-- > 0)
        *ptr++ = c;
    return (s);
}

/*int    main (void)
{
    unsigned char    s[50] = "Il fait beau aujourd'hui !";
    printf("Normal string : %s", str);
    ft_memset(s, '&', 12);
    printf("\nModified string : %s\n", s);
    return (0);
}*/