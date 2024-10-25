/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:16:18 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/28 00:39:53 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(t_cchar *s1, t_cchar *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = (char *)ft_calloc(i + 1, sizeof (char));
	if (res == 0)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j + i] = s2[i];
		i++;
	}
	res[j + i] = 0;
	return (res);
}

char	*ft_strjoin_set(t_cchar **strarr, size_t n, char *sep)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!strarr || !sep)
		return (NULL);
	j = ft_strlen_arr(strarr, n) + (n - 1) * ft_strlen(sep) + 1;
	res = (char *)ft_calloc(j, sizeof (char));
	if (res == 0)
		return (NULL);
	ft_strlcat(res, strarr[0], j);
	i = 1;
	while (i < n && res)
	{
		ft_strlcat(res, sep, j);
		ft_strlcat(res, strarr[i], j);
		i++;
	}
	return (res);
}

static size_t	calc_lenw(t_cchar *s1, t_cchar *set);

char	*ft_strtrim(t_cchar *s1, t_cchar *set)
{
	size_t	i;
	size_t	j;
	size_t	nl;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	nl = calc_lenw(s1, set);
	dest = (char *)ft_calloc(nl + 1, sizeof(char));
	if (dest == 0)
		return (NULL);
	i = 0;
	while (ft_cisinstr(s1[i], set))
		i++;
	j = 0;
	while (j < nl)
	{
		dest[j] = s1[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static size_t	calc_lenw(t_cchar *s1, t_cchar *set)
{
	int		i;
	int		j;
	int		mark;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (ft_cisinstr(s1[i], set))
		i++;
	j = 0;
	mark = -1;
	while (s1[i + j])
	{
		if (ft_cisinstr(s1[i + j], set) && mark == -1)
			mark = j;
		if (!ft_cisinstr(s1[i + j], set))
			mark = -1;
		j++;
	}
	if (mark == -1)
		mark = j;
	return (mark);
}
