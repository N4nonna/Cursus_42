/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:59:50 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 17:04:10 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

unsigned int    ft_strlcpy (char *dest, char *src, unsigned int size)
{
    unsigned int i;

    i = 0;
    if (src[i] == '\0')
        return (0);
    while (i < size - 1 && src[i])
    {
        dest[i] = src [i];
        i++;
    }
    if (size > 0)
        dest[i] = '\0';
    while (src[i] != '\0')
        i++;
    return (i);
}