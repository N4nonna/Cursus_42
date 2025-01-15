/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:12:57 by mby               #+#    #+#             */
/*   Updated: 2025/01/14 15:07:03 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

# include <define.h>
# include <proto.h>
# include <struct.h>

/* MAIN.C
************************************************************************** */
void	init_data(t_data *data, int ac, char **av);
int		create_env(t_data *data, char **env);
int		empty_line(char *line);
int		parse_line(t_data *data, char *line);
int		main(int ac, char **av, char **env);


/* EXECUTION
************************************************************************** */



/* PARSING
************************************************************************** */
// quote.c
void	quote_type(bool *dq, bool *sq, int *index, char c);
int		open_quote(t_data *data, char *line);
// utils.c
int		is_space(char c);
int		is_alpha(char c);


/* UTILS
************************************************************************** */
// free.c
void	free_all(t_data *data, char *msg, int *exit);
void	free_tokens(t_token *token);
void	free_cmds(t_cmd *cmd);

#endif