/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_end.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:05:14 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/21 13:40:52 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_m.h"

void	error_msg(char *err)
{
	perror(err);
	exit(1);
}

void	error(char *err)
{
	perror(err);
}

void	msg(char *err)
{
	write(2, err, ft_strlen(err));
}

void	free_parent(t_pipex *p)
{
	int	i;

	i = 0;
	close(p->infile);
	close(p->outfile);
	while (p->cmd_path[i])
		free(p->cmd_path[i++]);
	free(p->cmd_path);
	free(p->pipe);
}

void	free_pipe(t_pipex *p)
{
	close(p->infile);
	close(p->outfile);
	free(p->pipe);
	msg("PIPE ERROR");
	exit(1);
}
