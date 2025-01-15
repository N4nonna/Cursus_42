/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:24:38 by mby               #+#    #+#             */
/*   Updated: 2024/03/05 13:47:49 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_switchpoint(void **a, void **b)
{
	void	*t;

	if (!a || !b)
		return ;
	t = *a;
	*a = *b;
	*b = t;
}

void	ft_switchpointc(void *a, void *b, size_t n)
{
	size_t	i;

	if (!a || !b)
		return ;
	i = 0;
	while (i < n)
	{
		ft_switchchar(&((t_uchar *)a)[i], &((t_uchar *)b)[i]);
		i++;
	}
}

void	ft_switchchar(t_uchar *a, t_uchar *b)
{
	char	t;

	if (!a || !b)
		return ;
	t = *a;
	*a = *b;
	*b = t;
}

void	ft_switchint(int *a, int *b)
{
	int	t;

	if (!a || !b)
		return ;
	t = *a;
	*a = *b;
	*b = t;
}
