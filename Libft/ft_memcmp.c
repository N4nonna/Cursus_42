/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:24:07 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:24:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (s1 == s2)
		return (0);
	while (n-- > 0)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		us1++;
		us2++;
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
