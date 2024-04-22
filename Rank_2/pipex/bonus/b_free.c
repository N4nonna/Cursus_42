/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:05:14 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/22 13:53:40 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_all(t_pipex *p)
{
	close(p->infile);
	close(p->outfile);
	if (p->heredoc)
		unlink("here_doc.tmp");
}

void	free_child(t_pipex *p)
{
	int	i;

	i = 0;
	close_all(p);
	while (p->cmd_arg[i])
		free(p->cmd_arg[i++]);
	free(p->cmd_arg);
	free(p->cmd);
}

void	free_parent(t_pipex *p)
{
	int	i;

	i = 0;
	close_all(p);
	while (p->cmd_path[i])
		free(p->cmd_path[i++]);
	free(p->cmd_path);
	free(p->pipe);
}

void	free_pipe(t_pipex *p)
{
	close_all(p);
	free(p->pipe);
	msg("PIPE ERROR");
	exit(1);
}

void	free_all(t_pipex *p)
{
	int	i;

	i = 0;
	close_all(p);
	while (p->cmd_arg[i])
	{
		free(p->cmd_arg[i]);
		p->cmd_arg[i++] = NULL;
	}
	free(p->cmd_arg);
	p->cmd_arg = NULL;
	free(p->cmd);
	p->cmd = NULL;
	i = 0;
	while (p->cmd_path[i])
	{
		free(p->cmd_path[i]);
		p->cmd_path[i++] = NULL;
	}
	free(p->cmd_path);
	p->cmd_path = NULL;
	free(p->pipe);
	p->pipe = NULL;
}
