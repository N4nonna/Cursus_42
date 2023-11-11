/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:59:50 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 17:04:10 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

size_t    ft_strlcpy (char *dest, char *src, size_t size)
{
    size_t i;

    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while (src[i] && (i < (size - 1)))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}