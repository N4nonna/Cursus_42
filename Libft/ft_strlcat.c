/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:05:53 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 10:48:02 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return(i);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    char *d;
    const char *s;
    size_t dlen;
    size_t n;

    *d = *dst;
    s = src;
    n = size;
    while (n-- != 0 && *d != '\0')
        d++;
    dlen = d - dst;
    n = size - dlen;
    
    if (n == 0)
        return (dlen - ft_strlen(s));

    while (*s != '\0')
    {
        if (n != 1)
        {
            *d++ = *s;
            n--;
        }
        *s++;
    }
    *d = '\0';
    return (dlen + (s - src));
}

/*int	main(int ac, char **av)
{
    if (ac == 4)
    {
        size_t size = atoi(av[3]);
        size_t ret = ft_strlcat(av[1], av[2], size);
        //size_t ret2 = strlcat(av[1], av[2], size);
        printf("My ft_strlcat : %ld\n", ret);
        //printf("Real strlcat : %ld\n", ret2);
    }
    return 0;
}

int	main()
{
	char	destination[] = "Coucou";
	const char	source[] = " les amis !!!!!!!";
	long unsigned int 	nb = 11;
	printf("%ld\n", ft_strlcat(destination, source, nb));
}*/