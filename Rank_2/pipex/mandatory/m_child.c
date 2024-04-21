/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_child.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:04:30 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/21 13:49:00 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_m.h"

void	free_child(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->cmd_arg[i])
		free(p->cmd_arg[i++]);
	free(p->cmd_arg);
	free(p->cmd);
}

void	child(char **av, char **env, t_pipex pip)
{
	pip.pid = fork();
	if (!pip.pid)
	{
		if (pip.index == 0)
			ft_dup2(pip.infile, pip.pipe[1], &pip);
		else
			ft_dup2(pip.pipe[0], pip.outfile, &pip);
		close_pipe(&pip);
		pip.cmd_arg = ft_split(av[2 + pip.index], ' ');
		pip.cmd = get_cmd(pip.cmd_path, pip.cmd_arg[0]);
		if (!pip.cmd)
		{
			error_msg("Child error");
			free_child(&pip);
			exit(1);
		}
		close(pip.infile);
		close(pip.outfile);
		execve(pip.cmd, pip.cmd_arg, env);
	}
}
