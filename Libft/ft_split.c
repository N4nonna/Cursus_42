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

static char		**ft_freeall(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_strndup_split(char const *s, size_t n)
{
	char	*dup;
	size_t		i;

	i = 0;
	dup = NULL;
	if (n == 0)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = ((char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
		|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	size_t		j;
	size_t		temp;

	i = 0;
	j = 0;
	if (!s || !c)
		return (0);
	split = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (i < ft_count_words(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		temp = j;
		split[i++] = ft_strndup_split(&s[temp], j - temp);
		if (split[i++] == 0)
			return (ft_freeall(split));
	}
	split[i] = NULL;
	return (split);
}

/*int main(int ac, char **av)
{
	char **s;
	int i;

	s = ft_split(av[1],av[2]);
	i = 0;
	(void)ac;
	while (s[i])
	{
		printf("||%s||\n", s[i]);
		i++;
	}
	free(s);
		return 0;
}*/