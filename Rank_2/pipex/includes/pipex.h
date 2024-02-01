/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:47:48 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/11 13:16:09 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

// ********** PIPEX.C **********
void	execute(char *cmd, char **env);
void	child(char **av, int *p_fd, char **env);
void	parent(char **av, int *p_fd, char **env);
int		main(int ac, char **av, char **env);

// ********** PIPEX_UTILS.C **********
void	handle_exit(int n_exit);
int		open_file(char *file, int in_out);
char	*get_env(char *name, char **env);
char	*get_path(char *cmd, char **env);

#endif