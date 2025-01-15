/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarr_def.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 12:39:04 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putintarr_def(t_cint *arr, size_t n)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	ft_putstr("\nStart int array\n");
	while (i < n)
	{
		ft_putuns(i);
		ft_putstr(" : ");
		ft_putnbr(arr[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("End int array\n");
}

void	ft_putintarr_fd_def(t_cint *arr, size_t n, int fd)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	ft_putstr_fd("\nStart int array\n", fd);
	while (i < n)
	{
		ft_putuns_fd(i, fd);
		ft_putstr_fd(" : ", fd);
		ft_putnbr_fd(arr[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	ft_putstr_fd("End int array\n", fd);
}
