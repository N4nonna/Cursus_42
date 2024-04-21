/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:28:44 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/21 15:53:41 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// home-made functions
# include "libft.h"
// pipe, dup2, access, execve, waitpid and fork
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
// write and read
# include <unistd.h>
// perror
# include <stdio.h>
// malloc, free and exit
# include <stdlib.h>
// open and unlink
# include <fcntl.h>
// errno
# include <errno.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		cmd_num;
	int		pipe_num;
	int		*pipe;
	int		index;
	int		heredoc;
	char	**cmd_path;
	char	*cmd;
	char	**cmd_arg;
	char	*env_path;
	pid_t	pid;
}	t_pipex;

// B_PIPEX
int		main(int ac, char **av, char **env);
void	close_pipe(t_pipex *pipex);
//void	create_pipe(t_pipex *pipex);
//void	outfile(char *av, t_pipex *pipex);
//void	infile(char **av, t_pipex *pipex);

// B_CHILD
void	child(char **av, char **env, t_pipex pip);

// B_HEREDOC
int		is_heredoc(char *av, t_pipex *p);
void	heredoc(char *av, t_pipex *p);

// B_UTILS
char	*get_cmd(char **path, char *arg);
void	ft_dup2(char zero, char one, t_pipex *p);
char	*get_path(char **env);

// B_END
void	error_msg(char *err);
void	msg(char *err);
void	free_child(t_pipex *p);
void	free_parent(t_pipex *p);
void	free_pipe(t_pipex *p);

#endif