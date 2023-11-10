/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:54 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 16:58:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int is_lower (char c)
{
    return (c >= 'a' && c <= 'z');
}

char *ft_toupper (char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_lower(str[i]))
            str[i] -= 32;
        i++;
    }
    return (str);
}