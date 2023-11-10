/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:10 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 17:00:40 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char *cs1;
    const char *cs2;
    int i;
    
    cs1 = (char *)s1;
    cs2 = (char *)s2;
    i = 0;
    if (n == 0)
        return (0);
    while (cs1[i] || cs2[i])
    {
        if (cs1[i] != cs2[i])
            return (cs1[i] - cs2[i]);
        i++;
    }
    return (0);
}

/*int main (void)
{
    const char s1 [50] = "123456";
    const char s2 [50] = "12345";
    int ret = ft_memcmp(s1, s2, 6);
    if (ret < 0)
        printf("s1 is less than s2.");
    else if (ret > 0)
        printf("s1 is greater than s2.");
    else if (ret == 0)
        printf("s1 is equal to s2.");
    return 0;
}*/