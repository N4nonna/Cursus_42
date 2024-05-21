/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:28:00 by mescoda           #+#    #+#             */
/*   Updated: 2024/05/21 13:46:19 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <strings.h>
# include <stddef.h>
# include <stdarg.h>

// ********** FT_IS **********
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// ********** FT_MEM **********
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// ********** FT_PUT **********
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);

// ********** FT_STR **********
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *str);
char	*ft_strappend(char **s1, const char *s2);

// ********** FT_TO **********
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_tolower(int c);

// ********** FT_PRINTF **********
int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putnbr_base(unsigned int n, char c, char *base);
int		ft_printstr(char *str);
int		ft_printch(int c);
int		ft_printpercent(void);
int		ft_printpoint(unsigned long long ptr);

// ********** FT_GET **********
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024

char	*get_next_line(int fd);

// ********** FT_UTILS **********
void	ft_free_tab(char **tab);

// ********** FT_ **********

#endif
