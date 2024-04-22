/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_child.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:04:30 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/22 16:39:43 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(char **av, char **env, t_pipex p)
{
	char **tmp;

	p.pid = fork();
	if (!p.pid)
	{
		if (p.index == 0)
			ft_dup2(p.infile, p.pipe[1], &p);
		else
			ft_dup2(p.pipe[0], p.outfile, &p);
		close_pipe(&p);
		if (ft_strncmp("/", av[2 + p.index], 1))
		{
			p.cmd_arg = ft_split(av[2 + p.index], ' ');
			p.cmd = get_cmd(p.cmd_path, p.cmd_arg[0]);
		}
		else
		{
			if (access(av[2 + p.index], 0) == 0)
			{
				p.cmd = av[2 + p.index];
				tmp = ft_split(p.cmd, '/');
				p.cmd_arg = &tmp[1];
			}
			else
			{
				p.cmd = NULL;
				p.cmd_arg = NULL;
			}
		}
		if (!p.cmd)
			perror_free(p.cmd, &p);
		close(p.infile);
		close(p.outfile);
		execve(p.cmd, p.cmd_arg, env);
	}
}
