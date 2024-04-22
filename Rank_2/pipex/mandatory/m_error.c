/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:30:18 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/22 16:36:01 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	perror_msg(char *err)
{
	perror(err);
}

void	perror_free(char *err, t_pipex *p)
{
	perror(err);
	free_all(p);
	exit(1);
}

void	msg(char *err)
{
	write(2, err, ft_strlen(err));
}

void	msg_ex(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

void	perror_ex(char *err)
{
	perror(err);
	exit(1);
}
