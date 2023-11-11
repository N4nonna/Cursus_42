/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:42:17 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 20:56:02 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int i;

    i = ft_strlen(str);
    while (i >= 0)
    {
        if (str[i] == c)
            return ((char *)str + i);
        i--;
    }
    return (0);
}
