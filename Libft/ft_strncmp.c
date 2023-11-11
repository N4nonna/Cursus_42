/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:29:32 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 16:49:37 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int ft_strncmp (char *s1, char *s2, size_t n)
{
    unsigned char *us1;
    unsigned char *us2;
    
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