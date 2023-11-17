/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:56 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 17:18:33 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)s - 1);
	}
	return (NULL);
}

/*int main (void)
{
    const unsigned char s[] = {0, 1, 2, 3, 4, 5};
    char *ret;
	int test = 2;
    ret = ft_memchr(s, test, 3);
    printf("%s --> %s", s, ret);
	printf("%d\n", test);
    return (0);
}*/
