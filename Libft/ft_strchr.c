/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:03:09 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 12:42:50 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    while (*str && *str != c)
        str++;
    if (*str == c)
        return ((char *)str);
    return (0);
}

/*int main (void)
{
    const char *str = "Il fait beau aujourd'hui !";
    int c = '\0';
    printf ("le reponse est : %s", ft_strchr(str, c));
}*/