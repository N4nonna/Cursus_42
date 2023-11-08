/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:19:58 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 15:21:04 by mescoda          ###   ########.fr       */
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
    write (fd, "\n", 2);
}

/*int main()
{
    ft_putstr_fd("Les fraises sont bonnes", 1);
}*/