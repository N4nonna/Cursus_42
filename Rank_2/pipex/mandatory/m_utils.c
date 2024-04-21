/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:53:17 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/21 13:39:55 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_m.h"

char	*get_cmd(char **path, char *arg)
{
	char	*tmp;
	char	*cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		path++;
	}
	return (NULL);
}

void	ft_dup2(char zero, char one, t_pipex *pip)
{
	if (pip->infile == -1 && pip->index == 0)
	{
		if (pip->outfile > 0)
			close(pip->outfile);
		close_pipe(pip);
		exit(1);
	}
	if (pip->outfile == -1 && pip->index)
	{
		if (pip->infile > 0)
			close(pip->infile);
		close_pipe(pip);
		exit(1);
	}
	dup2(zero, 0);
	dup2(one, 1);
}

char	*get_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}
