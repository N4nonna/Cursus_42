/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:06:30 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 18:08:33 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// GNL RETURNING CHAR
char	*get_next_line(int fd);

char	*str_join(const char *s1, const char *s2);
void	*calloc_bzero(size_t nmemb, size_t size);
char	*str_chr(const char *str, int c);

// GNL RETURNING INT
char	*str_add(char *str, char buff);
int		gnl(int fd, char **str);

#endif