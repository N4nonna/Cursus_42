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

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
    unsigned char *ptr;

    ptr = (unsigned char *)dest;
    if (dest == src)
        return (dest);
    while (*src && size - 1)
    {
        *(unsigned char *)dest = *(unsigned char *)src;
        dest++;
        src++;
        size--;
    }
    while (size)
    {
        *dest++ = '\0';
        size--;
    }
    return ((char *)ptr);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ret;

    if (len == 0 || start >= ft_strlen(s))
	{
		ret = malloc(sizeof(char));
		*ret = 0;
		return (ret);
	}
    ret = malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    *ret = 0;
    ret = ft_strncpy(ret, s + start, len + 1);
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