/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:03:09 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 17:09:14 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

char    *ft_strchr (const char *str, int c)
{
    char *temp;
    
    temp = (char *)str;
    while (*temp != '\0')
    {
        if (*temp == c)
            return (temp);
        temp++;
    }
    return (0);
}

/*int main (void)
{
    const char *str = "Il fait beau aujourd'hui !";
    int c = 'a';
    printf ("le reponse est : %s", ft_strchr(str, c));
}*/