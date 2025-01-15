/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:17:50 by mescoda           #+#    #+#             */
/*   Updated: 2025/01/14 15:07:36 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Check if the character is a space character.
 * @param c: the character to be checked.
 * @return `1` if char c is a space.
 * @return `0` if not.
 * @author @N4nonna
*/
int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

/**
 * @brief Check if the character is an alphabetic character.
 * @param c: The character to be checked.
 * @return `1` if char c is a letter; 
 * @return `0` if not.
 * @author @N4nonna
*/
int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
