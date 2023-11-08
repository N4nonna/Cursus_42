/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:08:36 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 22:13:36 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int slen)
{
	char	*ptr;

	*ptr = *dest;
	while (*src && slen--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ret;
    unsigned int slen;

    slen = len - start;
    ret = (char *) malloc(sizeof(char) * (slen + 1));

    if (!ret)
        return (NULL);
    ft_strncpy(ret, (s + start), slen);

    return (ret);
}

/*int main ()
{
    char const s[] = "Smelly animal : awesome possum !";
    int start = 16;
    int len = 35;
    
    printf("Original string : %s\n", s);
    char *ret = ft_substr(s, 16, 33);
    printf("New string : %s\n", ret);
    return (0);
}*/