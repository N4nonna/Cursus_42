/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:02:26 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/14 00:37:07 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static char		**ft_freeAll(char **split, size_t i)
{
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static size_t	ft_wordLen(char const *s, char c)
{
	size_t len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_strndup(char const *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (n == 0)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static size_t	ft_countWords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!*s)
		return (0);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		count++;
		while (s[i] && s[i] != c)
			i++;			
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	len;
	
	if (!s)
		return (0);
	count = ft_countWords(s, c);
	split = (char **) malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] && s[j] == c)
			j++;
		len = ft_wordLen(&s[j], c);
		split[i] = ft_strndup(&s[j], len);
		if (!split[i])
			return (ft_freeAll(split, i));
		j = j + len;
		i++;
	}
	split[count] = NULL;
	return (split);
}
