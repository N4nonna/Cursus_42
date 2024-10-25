/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:17:50 by mescoda           #+#    #+#             */
/*   Updated: 2024/10/25 15:45:53 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Check if the character is a quote
		If the character is a quote and there is no quote
			Set the quote to true (opening quote) and increment the index
		Else if the character is a quote and there is a quote
			Set the quote to false (closing quote) and increment the index
*/

void	quote_type(bool *dq, bool *sq, int *index char c)
{
	if ((c == '"' || c == '\'') && (!*sq && !*dq))
	{
		if (c == '"' && !*dq)
			*dq = true;
		else if (c == '\'' && !*sq)
			*sq = true;
		++(*index);
	}
	else if (c == '"' || c == '\'')
	{
		if (c == '"' && *dq)
			*dq = false;
		else if (c == '\'' && *sq)
			*sq = false;
		++(*index);
	}
}

/*
	Loop through the line
		Check if the character is a quote
			If there is no quote
				Increment the index
	If there is an unclosed quote
		Print the error message
		Set the exit status to 2
		Return 1
	Return 0
*/

int	open_quote(t_data *data, char *line)
{
	int		i;
	bool	dq;
	bool	sq;

	i = 0;
	dq = false;
	sq = false;
	while (line && line[i])
	{
		quote_type(&dq, &sq, &i, line[i]);
		if (line[i] &&  (line[i] != '\'' && line[i] != '"')
			i++;
	}
	if (sq || dq)
	{
		ft_putstr_fd("minishell: syntax error\nOpen quote\n", 1);
		data->exit = 2;
		return (1);
	}
	return (0);
}
