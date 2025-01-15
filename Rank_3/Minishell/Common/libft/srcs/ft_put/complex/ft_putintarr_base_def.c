/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarr_base_def.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/06 12:39:10 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putintarr_base_def(t_cint *arr, t_cchar *base, size_t n)
{
	size_t	i;

	if (!arr)
		return ;
	if (!base)
	{
		ft_putintarr_def(arr, n);
		return ;
	}
	i = 0;
	ft_putstr("Start int array in base ");
	ft_putstr(base);
	ft_putstr("\n");
	while (i < n)
	{
		ft_putuns(i);
		ft_putstr(" : ");
		ft_putnbr_base(arr[i], base);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("End int array\n");
}

void	ft_putintarr_base_fd_def(t_cint *arr, t_cchar *base, size_t n, int fd)
{
	size_t	i;

	if (!arr)
		return ;
	if (!base)
	{
		ft_putintarr_fd_def(arr, n, fd);
		return ;
	}
	i = 0;
	ft_putstr_fd("Start int array in base ", fd);
	ft_putstr_fd(base, fd);
	ft_putstr_fd("\n", fd);
	while (i < n)
	{
		ft_putuns_fd(i, fd);
		ft_putstr_fd(" : ", fd);
		ft_putnbr_base_fd(arr[i], base, fd);
		ft_putstr_fd("\n", fd);
	}
	ft_putstr_fd("End int array\n", fd);
}
