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

int	ft_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while(sep[i])
	{
		if (c == sep[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_words(char *str, char *sep)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] && (ft_is_sep(str[i], sep) == 0) && flag == 0)
			flag = 1;
		if (str[i] && (ft_is_sep(str[i], sep) == 1) && flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

int		ft_strlen_split(char *src, char *sep)
{
	int	i;

	i = 0;
	while (src[i] && ft_is_sep(src[i], sep))
		i++;
	return (i);
}

char	*ft_strdup_split(char *str, char *sep)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_split(str, sep);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (0);
	while (str[i] && ft_is_sep(str[i], sep) == 1)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		count_words;

	i = 0;
	j = 0;
	count_words = ft_count_words(str, charset);
	split = (char **) malloc(sizeof(char *) * (count_words + 1));
	if (split == NULL)
		return (0);
	while (i < count_words)
	{
		while (ft_is_sep(str[j], charset) == 0)
			j++;
		split[i] = ft_strdup_split(&str[j], charset);
		j = j + ft_strlen_split(split[i], charset);
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