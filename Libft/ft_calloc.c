/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:39:03 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 14:51:40 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;

    if (nmemb == 0 || size == 0)
        nmemb = size = 1;
    ptr = malloc(nmemb * size);
    if (ptr)
        ft_bzero(ptr, (nmemb * size));
    return (ptr);
}
