/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:55:33 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 23:10:17 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n-- > 0)
        *ptr++ = '\0';
    printf("my ft_bzero : %s\n", (unsigned char *)s);
}

/*int main (int ac, char **av)
{
    if (ac == 3)
    {
        printf("original string : %s\n", av[1]);
        ft_bzero(av[1] + 3, atoi(av[2]));
    }
    return (0);
}*/