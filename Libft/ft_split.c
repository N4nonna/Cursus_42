/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:02:26 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 15:02:49 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] && (s[i] == c) && flag == 0)
			flag = 1;
		if (s[i] && (s[i] != c) && flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

int		ft_strlen_split(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char	*ft_strdup_split(char const *s, char c)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_split(s, c);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		dup[i] = ((char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		count_words;

	i = 0;
	j = 0;
	if (!s || !c)
		return (0);
	count_words = ft_count_words(s, c);
	split = (char **) malloc(sizeof(char *) * (count_words + 1));
	if (!split)
		return (NULL);
	while (i < count_words)
	{
		while (s[j] == c)
			j++;
		split[i] = ft_strdup_split(&s[j], c);
		j = j + ft_strlen_split(split[i], c);
		i++;
	}
	split[i] = 0;
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