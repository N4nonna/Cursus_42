/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:15:36 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 11:06:33 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    long unsigned int slen;

    i = 0;
    slen = ft_strlen(little);
    if (little == NULL || slen == 0)
        return ((char *)big);
    if (slen > len)
        return (NULL);
    while (i < len)
    {
        if (ft_strncmp((char *)&big[i], (char *)little, slen) == 0)
        {
            if (i + slen > len)
                return (NULL);
            return ((char *)&big[i]);
        }
        i++;
    }
    return (NULL);
}

/*int main(void)
{
    const char *s1 = "Il fait beau aujourd'hui !";
    const char *s2 = "beaU";
    char *ret = ft_strnstr(s1, s2, 27);

    printf("Original string : %s\nSearching this word : %s\nResult : %s", s1, s2, ret);
}*/