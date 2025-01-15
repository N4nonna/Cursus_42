/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:05:13 by mescoda           #+#    #+#             */
/*   Updated: 2025/01/14 15:05:51 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Determines the type of quote character.
 * @param dq: The status of the double quotes.
 * @param sq: The status of the single quotes.
 * @param index: The index of the character in the line.
 * @param c: The character to be checked.
 *
 * This function takes a character as input and modify the values of the
 * pointers dq and sq representing the status of the double and single quotes
 * respectively. It will increment the index of the character in the line.
 * 
 * It will also check if the character is an opening or closing quote
 * @author @N4nonna
 */
void	quote_type(bool *dq, bool *sq, int *index, char c)
{
	if ((c == '"' || c == '\'') && (*sq == false && *dq == false))
	{
		if (c == '"' && *dq == false)
			*dq = true;
		else if (c == '\'' && *sq == false)
			*sq = true;
		++(*index);
	}
	else if ((c == '"' && *dq == true) || (c == '\'' && *sq == true))
	{
		if (c == '"' && *dq == true)
			*dq = false;
		else if (c == '\'' && *sq == true)
			*sq = false;
		++(*index);
	}
}

/**
 * @brief Check if there are any open quote in the string.
 *
 * This function takes a string as input and returns an int depending of it's success or failling.
 * This function will search in our string for every quotation mark, using quote_type() to modify our boolean.
 * At the end of the string, if one of our boolean is still true, it means that one quote is still open.
 * We print an error and modify exit status in data.
 *
 * @param data: The struct were all our data is stored.
 * @param str: The input string to which the quotation mark will be appended.
 * @return `1` if the string has an open quote at the end; 
 * @return `0` if its a success.
 * @author @N4nonna
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
	if (sq == true || dq == true)
	{
		ft_putstr_fd("minishell: syntax error\nOpen quote\n", 1);
		data->exit = 2;
		return (1);
	}
	return (0);
}
