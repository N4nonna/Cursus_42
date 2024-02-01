/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:33 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/11 13:57:54 by mescoda          ###   ########.fr       */
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
		ft_putstr_fd("exec: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		handle_exit(1);
	if (pipe(p_fd) == -1)
		exit (-1);
	pid = fork();
	if (pid == -1)
		exit (-1);
	if (!pid)
		child(av, p_fd, env);
	parent(av, p_fd, env);
}
