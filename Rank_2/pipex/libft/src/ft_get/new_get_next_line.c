/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:30:54 by manon             #+#    #+#             */
/*   Updated: 2024/04/25 15:11:44 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *get_next_line(int fd)
{
    char    ret[7000000];
	char    *buff;
    int		i;
	int		b;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    b = read(fd, &buff, 1);
    i = 0;
    while (b > 0)
    {
        ret[i++] = *buff;
        if (*buff == '\n')
            break ;
        b = read(fd, &buff, 1);
    }
    ret[i] = '\0';
    if (b <= 0  && i == 0)
        return (NULL);
    return (ft_strdup(ret));
}
