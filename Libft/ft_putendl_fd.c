/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:24:54 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:24:55 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}

/*int main ()
{
	char *s1 = "lorem ipsum dolor sit amet";
	char *s2 = "  lorem\nipsum\rdolor\tsit amet  ";
	char *s3 = "";
	char *s4 = "lorem ipsum do\0lor sit amet";
	ft_putendl_fd(s1, 1);
	ft_putendl_fd(s2, 1);
	ft_putendl_fd(s3, 1);
	ft_putendl_fd(s4, 1);
}*/