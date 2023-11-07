/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:15:36 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 18:49:32 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string.h>
#include <stdio.h>

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    char    *haystack;
    char    *needle;
    char    *temp;

    haystack = (char *)big;
    needle = (char *)little;
    temp = haystack;
    if (*little == '\0')
        return (haystack);
    else if (needle - haystack < len)
        return (0);
    else
    {
        printf("%s --- %s --- %s\n", haystack, needle, temp);
        while ((*haystack != '\0' || *needle != '\0') && len--)
        {
            if (*haystack == *needle)
                temp = haystack;
            printf("%s --- %s --- %s\n", haystack, needle, temp);
            while ((*haystack == *needle) && (len > 0))
            {
                needle++;
                haystack++;
                printf("%s --- %s --- %s\n", haystack, needle, temp);
                if (*needle == '\0')
                {
                    printf("%s --- %s --- %s\n", haystack, needle, temp);
                    return (temp);
                    break;
                }
            }
            haystack++;
        }
        return (0);
    }
}

int main(void)
{
    const char *s1 = "Il fait beau aujourd'hui !";
    const char *s2 = "beau";
    char *ret = ft_strnstr(s1, s2, 10);

    printf("Original string : %s\nSearching this word : %s\nResult : %s", s1, s2, ret);
}