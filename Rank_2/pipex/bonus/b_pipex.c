/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:49:13 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/22 15:20:07 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	infile(char **av, t_pipex *pipex)
{
	if (pipex->heredoc)
		heredoc(av[2], pipex);
	else
		pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		perror_msg(av[1]);
}

static void	outfile(char *av, t_pipex *pipex)
{
	if (pipex->heredoc)
		pipex->outfile = open(av, O_CREAT | O_WRONLY | O_APPEND, 00644);
	else
		pipex->outfile = open(av, O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (pipex->outfile < 0)
		perror_msg(av);
}

static void	create_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_num - 1)
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
	while (i < pipex->pipe_num)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

// no pipe malloced for minishell
int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < is_heredoc(av[1], &pipex))
		msg_ex("Wrong number of argument");
	pipex.env_path = get_path(env);
	infile(av, &pipex);
	outfile(av[ac - 1], &pipex);
	pipex.cmd_num = ac - 3 - pipex.heredoc;
	pipex.pipe_num = 2 * (pipex.cmd_num - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_num);
	if (!pipex.pipe)
		free_pipe(&pipex);
	pipex.cmd_path = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_path)
		msg("Error comand");
	create_pipe(&pipex);
	pipex.index = -1;
	while (++pipex.index < pipex.cmd_num)
		child(av, env, pipex);
	close_pipe(&pipex);
	while (errno != ECHILD)
		waitpid(-1, NULL, 0);
	free_parent(&pipex);
	return (0);
}
