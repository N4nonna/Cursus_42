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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strcmp (char c, char *sep)
{
    unsigned int i;

    i= 0;
    while (sep[i])
    {
        if (c == sep[i])
            return (0);
        i++;
    }
    return (1);
}

int ft_endLen(char const *str, char const *set)
{
    int i;
    int endI;
    
    i = 0;
    endI = 0;
    while (str[i])
        i++;
    endI = i - 1;
    while (ft_strcmp(str[endI], (char *)set) == 0)
        endI--;
    return (endI);
}

int ft_startLen(char const *str, char const *set)
{
    int startI;

    startI = 0;
    while (ft_strcmp(str[startI], (char *)set) == 0)
        startI++;
    return (startI);
}

int ft_trimLen(char const *str, char const *set)
{
    int trimLen;
    
    trimLen = ft_endLen(str, set) - ft_startLen(str, set);
    return (trimLen);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *trim;
    int i;
    int len;
    int start;
    
    trim = NULL;
    i = 0;
    len = ft_trimLen(s1, set) + 1;
    start = ft_startLen(s1, set);
    if (s1 != NULL)
    {
        trim = (char *)malloc(len);
        while (i < len)
        {
            trim[i] = s1[start];
            i++;
            start++;
        }
        trim[i] = '\0';
    }
    return (trim);
}

/*int main (int ac, char **av)
{
    if (ac > 1)
    {
        printf("Original string : %s\n", av[1]); 
        printf("Element to trim : %s\n", av[2]);
        printf("Trimed string : %s\n", ft_strtrim(av[1], av[2]));
    }
    return 0;
}*/