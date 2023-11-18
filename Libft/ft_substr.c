/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:27:16 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/18 11:39:07 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	unsigned char	*ptr;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	slen;

	slen = len;
	if (!s)
		return (0);
	if (len == 0 || start >= ft_strlen(s))
	{
		ret = malloc(sizeof(char));
		*ret = 0;
		return (ret);
	}
	if (len >= ft_strlen(s))
	{
		slen = ft_strlen(s) - start;
		ret = (char *)malloc(sizeof(char) * (slen + 1));
	}
	else
		ret = (char *)malloc(sizeof(char) * (slen + 1));
	if (!ret)
		return (NULL);
	*ret = 0;
	ret = ft_strncpy(ret, s + start, slen + 1);
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
