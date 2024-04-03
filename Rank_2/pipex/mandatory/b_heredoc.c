/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_heredoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:36:34 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/03 15:37:50 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_heredoc(char *av, t_pipex *p)
{
	if (!ft_strncmp("here_doc", av, 9))
	{
		p->heredoc = 1;
		return (6);
	}
	else
	{
		p->heredoc = 0;
		return (5);
	}
}

static void	heredoc_error(char *msg)
{
	unlink("here_doc.tmp");
	write(2, msg, ft_strlen(msg));
}

//stop after writting on line on terminal (but do cmd nontheless)
void	heredoc(char *av, t_pipex *p)
{
	int		tmp;
	char	*buff;

	tmp = open("here_doc.tmp", O_CREAT | O_WRONLY | O_APPEND, 00644);
	if (tmp < 0)
		msg("Here_doc error");
	while (1)
	{
		write(1, "here_doc>", 9);
		buff = get_next_line(0);
		if (buff)
			exit(1);
		if (!ft_strncmp(av, buff, ft_strlen(av) + 1))
			break ;
		write(tmp, &buff, ft_strlen(buff));
		write(tmp, "\n", 1);
		free(buff);
	}
	free(buff);
	close(tmp);
	p->infile = open("here_doc.tmp", O_RDONLY);
	if (p->infile < 0)
		heredoc_error("Here_doc error");
}
