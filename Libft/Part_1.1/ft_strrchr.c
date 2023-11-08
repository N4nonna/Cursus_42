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

#include <stdio.h>

char    *ft_strchr(const char *str, int c)
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

char    *ft_strrchr(const char *str, int c)
{
    const char *found; 
    const char  *p;
    
    c = (unsigned char) c;
    found = NULL;
    if (c == '\0')
        return (NULL);
    while ((p = ft_strchr (str, c)) != NULL)
    {
        found = p;
        str = p + 1;
    }
    return ((char *)found);
}

/*int main (void)
{
    const char *str = "Il fait beau aujourd'hui !";
    int c = 'a';
    printf ("le reponse est : %s", ft_strrchr(str, c));
}*/