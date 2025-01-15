/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aarrtoparr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:48:24 by mby               #+#    #+#             */
/*   Updated: 2024/03/25 11:51:30 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	**ft_aarrtoparr_c(t_cchar **strarr, size_t n)
{
	void	**ret;
	size_t	i;

	if (!strarr)
		return (NULL);
	ret = (void **)ft_calloc(n - 1, sizeof(void *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n - 1)
	{
		ret[i] = ft_strdup(strarr[i]);
		if (!ret[i])
			return (ft_freeparr(ret, i), NULL);
		i++;
	}
	return (ret);
}

char	**ft_parrtoaarr_c(void **arr, size_t na)
{
	char	**ret;
	size_t	i;

	if (!arr)
		return (NULL);
	ret = (char **)ft_calloc(na + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < na)
	{
		ret[i] = ft_strdup(arr[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_parrtoaarr_m(void **arr, size_t na)
{
	char	**ret;
	size_t	i;

	if (!arr)
		return (NULL);
	ret = (char **)ft_calloc(na + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < na)
	{
		ret[i] = arr[i];
		i++;
	}
	ret[i] = NULL;
	free(arr);
	return (ret);
}
