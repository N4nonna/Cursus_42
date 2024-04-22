/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:53:17 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/22 16:40:09 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_cmd(char **path, char *arg)
{
	char	*tmp;
	char	*cmd;

	while (*path)
	{
		if (arg == NULL)
			return (NULL);
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

void	ft_dup2(char zero, char one, t_pipex *p)
{
	if (p->infile == -1 && p->index == 0)
	{
		if (p->outfile > 0)
			close(p->outfile);
		close_pipe(p);
		exit(1);
	}
	if (p->outfile == -1 && p->index)
	{
		if (p->infile > 0)
			close(p->infile);
		close_pipe(p);
		exit(1);
	}
	dup2(zero, 0);
	dup2(one, 1);
}

char	*get_path(char **env)
{

	while (*env != NULL)
	{
		while (ft_strncmp("PATH", *env, 4))
			env++;
		return (*env + 5);
	}
	perror_ex(*env);
	return (NULL);
}
