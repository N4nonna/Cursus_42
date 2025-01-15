/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:37:22 by mby               #+#    #+#             */
/*   Updated: 2024/02/26 15:30:48 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_power(int n, int p)
{
	int	ret;

	if (n == 0)
		return (0);
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	ret = 1;
	while (p != 0)
	{
		ret *= n;
		p--;
	}
	return (ret);
}

t_llint	ft_powerll(t_llint n, t_llint p)
{
	t_llint	ret;

	if (n == 0)
		return (0);
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	printf("test\n");
	ret = 1;
	while (p != 0)
	{
		ret *= n;
		p--;
	}	
	return (ret);
}
