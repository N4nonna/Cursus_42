/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:33 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/10 14:58:59 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		perror("exec ");
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		ft_free_tab(s_cmd);
		exit(127);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	if (dup2(fd, STDIN_FILENO) == -1)
		close(STDIN_FILENO);
	if (dup2(p_fd[1], STDOUT_FILENO) == -1)
		close(STDOUT_FILENO);
	close(p_fd[0]);
	close(p_fd[1]);
	close(fd);
	execute(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit (EXIT_FAILURE);
	if (dup2(fd, STDOUT_FILENO) == -1)
		close(STDOUT_FILENO);
	if (dup2(p_fd[0], STDIN_FILENO) == -1)
		close(STDIN_FILENO);
	close(p_fd[1]);
	close(p_fd[0]);
	close(fd);
	execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		perror("./pipex infile cmd cmd outfile\n");
		exit (127);
	}
	if (pipe(p_fd) == -1)
		exit (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		perror("Fork ");
	if (!pid)
		child(av, p_fd, env);
	if (pipe(p_fd) == -1)
		exit (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		perror("Fork ");
	if (!pid)
		parent(av, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
}
