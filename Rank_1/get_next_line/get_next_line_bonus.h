/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:06:30 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/27 18:01:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE__BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);

#endif