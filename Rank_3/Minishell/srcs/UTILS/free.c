/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:17:53 by mescoda           #+#    #+#             */
/*   Updated: 2024/10/25 16:39:14 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Not good for now

void	free_tokens(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp->value);
		free(tmp->type);
		free(tmp);
	}
	free(token);
}

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->cmd);
		free(tmp);
	}
}

void	free_all(t_data *data, char *msg, int *exit)
{
	int		i;

	i = 0;
	while (data->env[i])
		free(data->env[i++]);
	free(data->env);
	free_tokens(data->token);
	free_cmds(data->cmd);
	ft_putstr_fd(msg, 1);
	exit(exit);
}
