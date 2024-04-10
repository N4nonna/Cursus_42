/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:49:13 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/10 15:06:59 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_m.h"

static void	infile(char *av, t_pipex *pipex)
{
	pipex->infile = open(av, O_RDONLY);
	if (pipex->infile < 0)
		error_msg("Infile error");
}

static void	outfile(char *av, t_pipex *pipex)
{
	pipex->outfile = open(av, O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (pipex->outfile < 0)
		msg("Outfile error");
}

static void	create_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			free_parent(pipex);
		i++;
	}
}

void	close_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

// no pipe malloced for minishell
int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		msg("Wrong number of argument");
	infile(av[1], &pipex);
	outfile(av[ac - 1], &pipex);
	pipex.pipe = (int *)malloc(sizeof(int) * 2);
	if (!pipex.pipe)
		free_pipe(&pipex);
	pipex.env_path = get_path(env);
	pipex.cmd_path = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_path)
		msg("Error comand");
	create_pipe(&pipex);
	pipex.index = -1;
	while (++pipex.index < 2)
		child(av, env, pipex);
	close_pipe(&pipex);
	while (errno != ECHILD)
		waitpid(-1, NULL, 0);
	free_parent(&pipex);
	return (0);
}
//valgrind --trace-children=yes --track-fds=yes
//--leaks-check=full in terminal not vscode