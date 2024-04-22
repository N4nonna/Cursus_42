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
	p.pid = fork();
	if (!p.pid)
	{
		if (p.index == 0)
			ft_dup2(p.infile, p.pipe[1], &p);
		else
			ft_dup2(p.pipe[0], p.outfile, &p);
		close_pipe(&p);
		p.cmd_arg = ft_split(av[2 + p.index], ' ');
		p.cmd = get_cmd(p.cmd_path, p.cmd_arg[0]);
		if (!p.cmd)
			perror_free(p.cmd, &p);
		close(p.infile);
		close(p.outfile);
		execve(p.cmd, p.cmd_arg, env);
	}
}
