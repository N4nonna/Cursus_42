/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:50:13 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 16:56:36 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int is_upper (char c)
{
    return (c >= 'A' && c <= 'Z');
}

char *ft_tolower (char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_upper(str[i]))
            str[i] += 32;
        i++;
    }
    return (str);
}