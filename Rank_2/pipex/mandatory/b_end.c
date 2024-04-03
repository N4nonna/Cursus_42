/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_end.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:05:14 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/03 12:28:38 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*if outfile error, cmd need to act and not just exit*/
void	error_msg(char *err)
{
	perror(err);
	exit(1);
}

void	msg(char *err)
{
	write(2, err, ft_strlen(err));
}

void	free_child(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->cmd_arg[i])
		free(p->cmd_arg[i++]);
	free(p->cmd_arg);
	free(p->cmd);
}

void	free_parent(t_pipex *p)
{
	int	i;

	i = 0;
	close(p->infile);
	close(p->outfile);
	if (p->heredoc)
		unlink("here_doc.tmp");
	while (p->cmd_path[i])
		free(p->cmd_path[i++]);
	free(p->cmd_path);
	free(p->pipe);
}

void	free_pipe(t_pipex *p)
{
	close(p->infile);
	close(p->outfile);
	if (p->heredoc)
		unlink("here_doc.tmp");
	free(p->pipe);
	msg("PIPE ERROR");
	exit(1);
}
