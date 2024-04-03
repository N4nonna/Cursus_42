/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_child.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:04:30 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/01 14:36:04 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(char **av, char **env, t_pipex pip)
{
	pip.pid = fork();
	if (!pip.pid)
	{
		if (pip.index == 0)
			ft_dup2(pip.infile, pip.pipe[1]);
		else if (pip.index == pip.cmd_num - 1)
			ft_dup2(pip.pipe[2 * pip.index - 2], pip.outfile);
		else
			ft_dup2(pip.pipe[2 * pip.index - 2], pip.pipe[2 * pip.index + 1]);
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
