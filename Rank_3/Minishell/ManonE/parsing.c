/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:06:30 by mescoda           #+#    #+#             */
/*   Updated: 2025/02/22 14:36:39 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_token
{
	char		*str;
	int			type;
	t_token		*next;
}			t_token;

char	*str_redir(char **line, int index)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = index;
	while (line)
	{
		if (*line[j + 1] == '|')
			break ;
		j++;
	}
	str = ft_strndup(&line[index], j - index);
	return (str);
}

int	pipechar(t_token *token, char *line, int index)
{
	token = token->next;
	token.type = PIPE;
	token = token->next;
	token.type = CMD;
	index++;
	return (index);
}

int	metachar(t_token *token, char *line, int index, t_subcmd *subcmd)
{
	if (line[index] == '|')
		index = pipechar(&token, line, index);
	if (line[index] == '>')
	{
		if (line[index + 1] == '>')
			addredir(APPEND, str_redir(&line, index), subcmd);
		else
			addredir(TRUNC, str_redir(&line, index), subcmd);
		token = token->next;
		token->type = CMD;
		index += ft_strlen(str_redir(&line, index) + 1);
	}
	else if (line[index] == '<')
	{
		if (line[index + 1] == '<')
			addredir(IF_HEREDOC, str_redir(&line, index), subcmd);
		else
			addredir(INFILE, str_redir(&line, index), subcmd);
		token = token->next;
		token->type = CMD;
		index += ft_strlen(str_redir(&line, index) + 1);
	}
	return (index);
}

int	parsing(char **line, t_subcmd *subcmd)
{
	t_token			token;
	int				i;
	int				j;
	int				k;

	i = -1;
	j = 0;
	k = 0;
	token = ft_lstnew(NULL);
	if (!token)
		return (ft_dprintf(2, "malloc fail : parsing\n"), 1);
	while (line[++i] && line[i][j])
	{
		j = 0;
		if ((line[i][j] == '|' || line[i][j] == '>' || line[i][j] == '<') \
		&& check_quote(&token, line)) // <-- HERE
		{
			token.str[k] = '\0';
			j = metachar(&token, line[i], j, subcmd);
			k = 0;
		}
		else
			token.str[k++] = line[i][j++];
	}
	return (0);
}

