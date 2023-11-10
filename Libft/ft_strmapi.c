/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:23:02 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/10 12:50:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    unsigned int len;
    char    *str;

    i = 0;
    len = ft_strlen((char *)s);
    str = NULL;
    if (!s || !f)
        return (str);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (0);
    while (i < len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

/*char f(unsigned int i, char c)
{
    char str;
    str = c + 1;
    return (str);
}

int main ()
{
    char const *string = "Hello, World!";
    printf("Original string : %s\n", string);
    char *ret = ft_strmapi(string, *f);
    printf("New string : %s\n", ret);
    return 0;
}*/