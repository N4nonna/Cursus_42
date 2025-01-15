/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:15:02 by mabonny-          #+#    #+#             */
/*   Updated: 2025/01/14 15:01:20 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define PP_STDIN 1
# define PP_PIPEIN 2
# define PP_FILEIN 3
# define PP_HEREDOC 4

# define PP_STDOUT 1
# define PP_PIPEOUT 2
# define PP_FILEOUT 3

typedef struct s_data
{
	t_env		*env;
	t_token		*token;
	t_cmd		*cmd;
	int			exit;
}				t_data;

typedef struct s_env
{
	char		*lst;
	t_env		*next;
	t_env		*prev;
}				t_env;

typedef struct s_token
{
	int			type;
	char		*value;
	t_token		*next;
	t_token		*prev;
}				t_token;

typedef struct s_piedpipappend_modeer
{
	int			in_stat;
	char		*in_file;
	int			out_stat;
	char		*out_file;
	int			append_mode;
}				t_piedpiper;

typedef struct s_cmd
{
	char		*cmd;
	char		*exec;
	char		**args;
	int			argc;
	t_piedpiper	*pp;
}				t_cmd;

#endif