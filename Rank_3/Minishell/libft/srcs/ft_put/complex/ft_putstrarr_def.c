/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr_def.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/25 12:21:45 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstrarr_def(t_cchar **arr, size_t n)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	ft_putstr("\nStart str array\n");
	while (i < n && arr[i])
	{
		ft_putuns(i);
		ft_putstr(" : \"");
		ft_putstr(arr[i]);
		ft_putstr("\"\n");
		i++;
	}
	ft_putstr("End str array\n");
}

void	ft_putstrarr_fd_def(t_cchar **arr, size_t n, int fd)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	ft_putstr_fd("\nStart str array\n", fd);
	while (i < n && arr[i])
	{
		ft_putuns_fd(i, fd);
		ft_putstr_fd(" : \"", fd);
		ft_putstr_fd(arr[i], fd);
		ft_putstr_fd("\"\n", fd);
		i++;
	}
	ft_putstr_fd("End str array\n", fd);
}
