/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:30:11 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 12:30:14 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum (int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z')
        || (c >= '0' && c<= '9'));
}
