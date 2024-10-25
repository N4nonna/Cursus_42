/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:33:18 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/26 18:59:22 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z' ) || ('a' <= c && c <= 'z'));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isalnum(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'));
}

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

int	ft_isascii(int c)
{
	return ((0 <= c && c <= 127));
}
