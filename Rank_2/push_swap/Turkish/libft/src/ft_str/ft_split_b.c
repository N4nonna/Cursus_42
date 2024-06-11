/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:36:51 by manon             #+#    #+#             */
/*   Updated: 2024/06/11 11:59:53 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next(char *s, char c)
{
	static int	cursor = 0;
	char		*next;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next = malloc((size_t)len * sizeof(char) + 1);
	if (!next)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next[i++] = s[cursor++];
	next[i] = '\0';
	return (next);
}

char	**ft_split_b(char *s, char c)
{
	int		word_count;
	char	**res;
	int		i;

	i = 0;
	word_count = count_word(s, c);
	if (!word_count)
		exit(1);
	res = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!res)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ;
		}
		res[i++] = get_next(s, c);
	}
	res[i] = NULL;
	return (res);
}
