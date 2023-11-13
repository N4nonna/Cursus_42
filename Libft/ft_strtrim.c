/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:02:40 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/10 12:14:15 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static int ft_strcmp (unsigned char c, unsigned char *s2)
{
    unsigned int i;

    i= 0;
    while (s2[i])
    {
        if (c == s2[i])
            return (0);
        i++;
    }
    return (1);
}

int ft_startLen(unsigned char *str, unsigned char *set)
{
    size_t i;

    i = 0;
    while (ft_strcmp(str[i], set) == 0)
        i++;
    if (ft_strlen((const char *)str) == i)
        return (0);
    return (i);
}

int ft_endLen(unsigned char *str, unsigned char *set)
{
    size_t i;
    
    i = 0;
    while (str[i])
        i++;
    i -= 1;
    while (ft_strcmp(str[i], set) == 0)
        i--;
    return (i - ft_startLen(str, set));
}

char *ft_strtrim(const char *s1, const char *set)
{
    char    *trim;
    unsigned char *uset;
    unsigned char *us1;
    size_t i;
    size_t len;
    size_t start;
    
    if (!s1 || !set)
        return (0);
    uset = (unsigned char *)set;
    us1 = (unsigned char *)s1;
    start = ft_startLen(us1, uset);
    len = ft_endLen(us1, uset) + 1;
    trim = (char *)malloc(sizeof(char) * (len + 1));
    if (!trim)
        return (NULL);
    i = 0;
    *trim = 0;
    while (i < len)
    {
            trim[i] = s1[start];
            i++;
            start++;
    }
    trim[i] = '\0';
    return (trim);
}
