/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:06:18 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 14:24:58 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ftu_split_set_nw(t_cchar *str, char *set)
{
	int	count;
	int	p;
	int	flag;

	if (!str || !set)
		return (0);
	p = 0;
	count = 0;
	flag = 1;
	while (str[p])
	{
		while (str[p] && ft_cisinstr(str[p], set))
		{
			p++;
			flag = 1;
		}
		while (str[p] && !ft_cisinstr(str[p], set))
		{
			if (flag == 1)
				count++;
			p++;
			flag = 0;
		}
	}
	return (count);
}

static size_t	ftu_split_set_process(char **res, t_cchar *str, char *set)
{
	size_t	word;
	int		z;
	int		p;

	if (!str || !set || !res)
		return (0);
	word = 0;
	z = -1;
	p = 0;
	while (str[p])
	{
		if (ft_cisinstr(str[p], set) || str[p + 1] == '\0')
		{
			if (p != z + 1 || (!ft_cisinstr(str[p], set) && str[p + 1] == '\0'))
			{
				res[word] = ft_strndup(&str[z + 1], p - z);
				if (res[word] == NULL)
					return (word);
				word++;
			}
			z = p;
		}
		p++;
	}
	return (res[word] = NULL, 0);
}

char	**ft_split_set(t_cchar *str, char *set)
{
	char	**res;
	size_t	pivot;

	if (str == NULL)
		return (NULL);
	res = (char **)ft_calloc((1 + ftu_split_set_nw(str, set)), sizeof (char *));
	if (res == 0)
		return (NULL);
	pivot = ftu_split_set_process(res, str, set);
	if (pivot != 0)
		return (ft_freeparr((void *)res, pivot), free(res), NULL);
	return (res);
}
