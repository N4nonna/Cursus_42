/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:24:44 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/10 14:47:47 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


int ft_isdigit(int c)
{
    return (c >= '0' && c<= '9');
}