/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_child.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:04:30 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/23 15:08:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	is_abspath(char *av, t_pipex *p)
{
	char	**tmp;

	if (ft_strncmp("/", av, 1))
	{
		p->cmd_arg = ft_split(av, ' ');
		p->cmd = get_cmd(p->cmd_path, p->cmd_arg[0]);
		if (!p->cmd)
			perror_free(p->cmd, p);
	}
	else
	{
		if (access(av, 0) == 0)
		{
			p->cmd = av;
			tmp = ft_split(p->cmd, '/');
			p->cmd_arg = &tmp[1];
			free(*tmp);
		}
		else
		{
			free_parent(p);
			perror_ex(av);
		}
	}
}

void	child(char **av, char **env, t_pipex p)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.index == 0)
			ft_dup2(p.infile, p.pipe[1], &p);
		else if (p.index == p.cmd_num - 1)
			ft_dup2(p.pipe[2 * p.index - 2], p.outfile, &p);
		else
			ft_dup2(p.pipe[2 * p.index - 2], p.pipe[2 * p.index + 1], &p);
		close_pipe(&p);
		is_abspath(av[2 + p.index + p.heredoc], &p);
		close(p.infile);
		close(p.outfile);
		execve(p.cmd, p.cmd_arg, env);
	}
}
