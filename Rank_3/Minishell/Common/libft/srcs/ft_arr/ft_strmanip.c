/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:33:22 by mby               #+#    #+#             */
/*   Updated: 2024/03/05 12:40:19 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrev(char *str)
{
	size_t	l;
	size_t	i;

	if (!str)
		return (NULL);
	l = ft_strlen(str);
	i = 0;
	while (i <= l / 2)
	{
		ft_switchchar(&((t_uchar *)str)[i], &((t_uchar *)str)[l - i - 1]);
		i++;
	}
	return (str);
}

void	ft_striteri(char *s, void (*f)(size_t, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
