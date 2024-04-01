/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:49:13 by mescoda           #+#    #+#             */
/*   Updated: 2024/03/27 16:10:17 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	infile(char **av, t_pipex *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		error_msg("Infile error");
}

void	outfile(char *av, t_pipex *pipex)
{
	pipex->outfile = open(av, O_CREAT | O_RDWR | O_TRUNC);
	if (pipex->outfile < 0)
		error_msg("Outfile error");
}

void	create_pipe(t_pipex *pipex)
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

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	infile(av, &pipex);
	outfile(av[ac - 1], &pipex);
	pipex.cmd_num = ac - 3;
	pipex.pipe_num = 2 * (pipex.cmd_num - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_num);
	if (!pipex.pipe)
		error_msg("Malloc error");//??
	pipex.env_path = get_path(env);
	pipex.cmd_path = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_path)
		error_msg("Error comand");
	create_pipe(&pipex);
	pipex.index = -1;
	while (++pipex.index < pipex.cmd_num)
		child(av, env, pipex);
	close_pipe(&pipex);
	waitpid(-1, NULL, 0);
	free_parent(&pipex);
	return (0);
}
