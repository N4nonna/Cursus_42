/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:33 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/12 18:34:20 by mescoda          ###   ########.fr       */
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
		perror("exec: command not found: ");
		ft_free_tab(s_cmd);
		exit(EXIT_FAILURE);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		exit (EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	execute(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit (EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		perror("./pipex infile cmd cmd outfile\n");
		exit (EXIT_FAILURE);
	}
	if (pipe(p_fd) == -1)
		exit (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit (EXIT_FAILURE);
	while (!pid)
		child(av, p_fd, env);
	parent(av, p_fd, env);
}
