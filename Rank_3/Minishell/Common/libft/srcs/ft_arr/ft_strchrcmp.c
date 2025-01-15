/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:17:02 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/10 16:22:58 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(t_cchar *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(t_cchar *s, int c)
{
	size_t		i;
	const char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	temp = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			temp = &s[i];
		i++;
	}
	if (s[i] == (char)c)
		temp = &s[i];
	return ((char *)temp);
}

int	ft_strcmp(t_cchar *s1, t_cchar *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(t_cchar *s1, t_cchar *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2 || !n)
		return (0);
	i = 0;
	while (i < n && (s1[i] == s2[i] && s1[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
