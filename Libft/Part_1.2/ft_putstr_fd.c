/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:14:37 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 15:19:29 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        write (fd, &s[i], 1);
        i++;
    }
}

/*int main()
{
    ft_putstr_fd("Les fraises sont bonnes", 1);
}*/