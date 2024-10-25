/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:19:26 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/25 11:02:12 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(t_cchar *src)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
	dest = (char *)ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(t_cchar *src, size_t n)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
	dest = (char *)ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strmap(t_cchar *s, char (*f)(size_t, char))
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	res = (char *)ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (res == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_substr(t_cchar *s, size_t start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)ft_strlen((char *)s) <= start)
		len = 0;
	i = 0;
	while (len != 0 && s[start + i] && i < len)
		i++;
	dest = (char *)ft_calloc(i + 1, sizeof(char));
	if (dest == 0)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
