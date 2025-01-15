/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:06:18 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/06/05 13:34:56 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	nbrwrd(const char *str, char c)
{
	int	count;
	int	p;
	int	flag;

	p = 0;
	count = 0;
	flag = 1;
	while (str[p])
	{
		while (str[p] && str[p] == c)
		{
			p++;
			flag = 1;
		}
		while (str[p] && str[p] != c)
		{
			if (flag == 1)
				count++;
			p++;
			flag = 0;
		}
	}
	return (count);
}

static char	*copy_word(const char *str, int lastsep, char c)
{
	size_t	i;
	size_t	j;
	char	*word;

	i = lastsep + 1;
	j = 0;
	while (str[i + j] != c && str[i + j] != '\0')
		j++;
	word = (char *)ft_calloc((j + 1), sizeof (char));
	if (!word)
		return (NULL);
	j = 0;
	while (str[i + j] != c && str[i + j] != '\0')
	{
		word[j] = str[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	clean(char **res, int word)
{
	int	i;

	i = 0;
	while (res[i] && i <= word)
	{
		free(res[i]);
		i++;
	}
}

static int	looper(char **res, const char *str, char c)
{
	int	word;
	int	z;
	int	p;

	word = 0;
	z = -1;
	p = 0;
	while (str[p])
	{
		if (str[p] == c || str[p + 1] == '\0')
		{
			if (p != z + 1 || (str[p] != c && str[p + 1] == '\0'))
			{
				res[word] = copy_word(str, z, c);
				if (res[word] == NULL)
					return (word);
				word++;
			}
			z = p;
		}
		p++;
	}
	res[word] = NULL;
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		pivot;

	if (str == NULL)
		return (NULL);
	res = (char **)ft_calloc((1 + nbrwrd(str, c)), sizeof (char *));
	if (res == 0)
		return (NULL);
	pivot = looper(res, str, c);
	if (pivot != 0)
	{
		clean(res, pivot);
		free(res);
		res = NULL;
	}
	return (res);
}
