/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:05:53 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 20:07:34 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *idest;
    const unsigned char   *isrc;
    
    idest = (unsigned char *)dest;
    isrc = (const unsigned char *)src;
    while (n-- > 0)
        *idest++ = *isrc++;
    return (dest);
}

void    *ft_memchr(void *s, int c, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n-- > 0)
    { 
        if (*ptr == c)
            return ((void *)ptr);
        ptr ++;
    }
    return (0);
}

size_t ft_strnlen(char *s, size_t maxlen)
{
    char*  p;
    
    p = ft_memchr(s, 0, maxlen);
    if (p == NULL)
        return maxlen;
    else
        return (p - s);
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return(i);
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t srclen;
    size_t dstlen;
    
    srclen = ft_strlen(src);
    dstlen = ft_strnlen(dst, size);
    if (dstlen == size) 
        return (size + srclen);
    if (srclen < size - dstlen)
        ft_memcpy((dst + dstlen), src, (srclen + 1));
    else
    {
        ft_memcpy((dst + dstlen), src, (size - dstlen - 1));
        dst[size - 1] = '\0';
    }
    return (dstlen + srclen);
}

/*int	main()
{
	char	destination[] = "This is ";
	const char	source[] = "a potentially long string";
	long unsigned int 	nb = 16;
	printf("My ft_strlcat : %ld\n", ft_strlcat(destination, source, nb));
    printf("Real strlcat : 33");
}*/