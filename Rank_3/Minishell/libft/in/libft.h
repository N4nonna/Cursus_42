/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mby <mby@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:40:23 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/09/23 17:44:39 by mby              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Need work :
- overflow
- test gpt
- sortlst
- command
- make proj
*/

#ifndef LIBFT_H
# define LIBFT_H 

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <strings.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif

# ifndef B_TEN
#  define B_TEN "0123456789"
# endif

# ifndef B_HEX_MAJ
#  define B_HEX_MAJ "0123456789ABCDEF"
# endif

# ifndef SPACES
#  define SPACES "\f\n\r\t\v "
# endif

# ifndef B_HEX_MIN
#  define B_HEX_MIN "0123456789abcdef"
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

typedef struct s_dlist
{
	void				*content;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}				t_dlist;

typedef unsigned int		t_uns;

typedef long long int		t_llint;

typedef long int			t_lint;

typedef long long unsigned	t_lluns;

typedef const char			t_cchar;

typedef unsigned char		t_uchar;

typedef const int			t_cint;

typedef const void			t_cvoid;

//////////////////
////  FT_ARR  ////
//////////////////

int		*ft_arrintiter(int *arr, size_t n, void (*f)(size_t, int*));
int		*ft_arrintrev(int *arr, size_t n);
int		*ft_arrintsort(int *arr, size_t n);
int		*ft_arrintrsortf(int *arr, size_t n, int (*f)(int, int));
int		*ft_arrintsortf(int *arr, size_t n, int (*f)(int, int));

int		*ft_arrintdup(int *arr, size_t n);
int		*ft_arrintmap(int *arr, size_t n, void (*f)(size_t, int*));

void	**ft_arrpiter(void **arr, size_t n, void (*f)(size_t, void*));
void	**ft_arrprev(void **arr, size_t n);

void	**ft_arrpdup(void **arr, size_t n);
void	**ft_arrpmap(void **arr, size_t n, void (*f)(size_t, void*));

size_t	ft_arrstrsize(char **arr);
char	**ft_arrstriter(char **arr, size_t n, void (*f)(size_t, char**));
char	**ft_arrstrrev(char **arr, size_t n);

char	**ft_arrstrdup(char **arr, size_t n);
char	**ft_arrstrmap(char **arr, size_t n, void (*f)(size_t, char*));

t_lint	ft_indexintarr(int *arr, size_t n, int nb);
t_lint	ft_indexintarr_set(int *arr, size_t na, int *set, size_t ns);
t_lint	ft_indexllintarr(t_llint *arr, size_t n, t_llint nb);
t_lint	ft_indexllintarr_set(t_llint *arr, size_t na, t_llint *set, size_t ns);

t_lint	ft_indexnintarr(int *arr, size_t n, int nb);
t_lint	ft_indexnintarr_set(int *arr, size_t na, int *set, size_t ns);
t_lint	ft_indexnllintarr(t_llint *arr, size_t n, t_llint nb);
t_lint	ft_indexnllintarr_set(t_llint *arr, size_t na, t_llint *set, size_t ns);

t_lint	ft_indexparr(t_cvoid **arr, size_t n, t_cvoid *p);
t_lint	ft_indexparr_set(t_cvoid **arr, size_t na, t_cvoid **set, size_t ns);
t_lint	ft_indexnparr(t_cvoid **arr, size_t n, t_cvoid *p);
t_lint	ft_indexnparr_set(t_cvoid **arr, size_t na, t_cvoid **set, size_t ns);

t_lint	ft_indexstr(t_cchar *str, t_cchar c);
t_lint	ft_indexstr_set(t_cchar *str, t_cchar *set);
t_lint	ft_indexnstr(t_cchar *str, t_cchar c);
t_lint	ft_indexnstr_set(t_cchar *str, t_cchar *set);

int		ft_iisinintarr(int nb, int *intarr, size_t na);
int		ft_isisinintarr(int *set, size_t ns, int *intarr, size_t na);
int		ft_iisainintarr(int nb, int *intarr, size_t na);
int		ft_isisainintarr(int *set, size_t ns, int *intarr, size_t na);
int		ft_intarrdoubles(int *intarr, size_t na);

int		ft_lliisinllintarr(t_llint nb, t_llint *intarr, size_t na);
int		ft_llisisinllintarr(t_llint *st, size_t m, t_llint *intarr, size_t n);
int		ft_lliisainllintarr(t_llint nb, t_llint *intarr, size_t na);
int		ft_llisisainllintarr(t_llint *st, size_t m, t_llint *intarr, size_t n);
int		ft_llintarrdoubles(t_llint *llintarr, size_t na);

int		ft_pisinparr(t_cvoid *p, t_cvoid **parr, size_t na);
int		ft_psisinparr(t_cvoid **parr, size_t na, t_cvoid **set, size_t ns);
int		ft_pisainparr(t_cvoid *p, t_cvoid **parr, size_t na);
int		ft_psisainparr(t_cvoid **parr, size_t na, t_cvoid **set, size_t ns);
int		ft_parrdoubles(t_cvoid **parr, size_t na);

char	**ft_split(t_cchar *str, char c);

char	**ft_split_set(t_cchar *str, char *set);

char	*ft_strchr(t_cchar *s, int c);
char	*ft_strrchr(t_cchar *s, int c);
int		ft_strcmp(t_cchar *s1, t_cchar *s2);
int		ft_strncmp(t_cchar *s1, t_cchar *s2, size_t n);

char	*ft_strjoin(t_cchar *s1, t_cchar *s2);
char	*ft_strjoin_set(t_cchar **strarr, size_t n, char *sep);
char	*ft_strtrim(t_cchar *s1, t_cchar *set);

size_t	ft_strlcat(char *dst, t_cchar *src, size_t size);
size_t	ft_strlcpy(char *dst, t_cchar *src, size_t size);

size_t	ft_strlen(t_cchar *str);
size_t	ft_strlen_arr(t_cchar **arrstr, size_t n);
size_t	ft_strnlen(t_cchar *str, size_t n);

void	ft_striteri(char *s, void (*f)(size_t, char*));
char	*ft_strrev(char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*ft_strdup(t_cchar *src);
char	*ft_strndup(t_cchar *src, size_t n);
char	*ft_strmap(t_cchar *s, char (*f)(size_t, char));
char	*ft_substr(t_cchar *s, size_t start, size_t len);

int		ft_cisinstr(t_cchar c, t_cchar *str);
int		ft_csisinstr(t_cchar *set, t_cchar *str);
int		ft_cisainstr(t_cchar c, t_cchar *str);
int		ft_csisainstr(t_cchar *set, t_cchar *str);
int		ft_strdoubles(t_cchar *str);

char	*ft_strstr(t_cchar *big, t_cchar *little);
char	*ft_strnstr(t_cchar *big, t_cchar *little, size_t len);

/////////////////
///  FT_LST  ////
/////////////////

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstremove(t_list **alst_from, t_list *target, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstswitch(t_list **alst, t_list *lst1, t_list *lst2);
void	ft_lstsortf(t_list *lst, int (*f)(void *, void *));
t_list	*ft_lstbestest(t_list *lst, int (*f)(void *, void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstdup(t_list *lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnth(t_list *lst, size_t n);
t_list	*ft_lstprev(t_list *lst_from, t_list *current);
size_t	ft_lstsize(t_list *lst);

int		ft_lstindex(t_list *lst_from, void *content);
int		ft_lstrank(t_list *lst_from, t_list *current);

t_list	*ft_lstworstest(t_list *lst, int (*f)(void *, void *));
t_list	*ft_lstbestest(t_list *lst, int (*f)(void *, void *));

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new);

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstremove(t_dlist **alst_from, t_dlist *target, void (*del)(void*));

void	ft_dlstsortf(t_dlist *dlst, int (*f)(void *, void *));
void	ft_dlstswitch(t_dlist **adlst, t_dlist *dlst1, t_dlist *dlst2);
t_dlist	*ft_dlstworstest(t_dlist *dlst, int (*f)(void *, void *));
t_dlist	*ft_dlstbestest(t_dlist *dlst, int (*f)(void *, void *));
void	ft_dlstiter(t_dlist *dlst, void (*f)(void *));

t_dlist	*ft_dlstmap(t_dlist *dlst, void*(*f)(void *), void(*del)(void *));
t_dlist	*ft_dlstdup(t_dlist *dlst, void (*del)(void *));

t_dlist	*ft_dlstfirst(t_dlist *dlst);
t_dlist	*ft_dlstlast(t_dlist *dlst);
t_dlist	*ft_dlstnth_next(t_dlist *dlst, size_t n);
t_dlist	*ft_dlstnth_prev(t_dlist *dlst, size_t n);

int		ft_dlstindex_next(t_dlist *dlst_start, void *content);
int		ft_dlstindex_prev(t_dlist *dlst_start, void *content);
int		ft_dlstrank_next(t_dlist *dlst_from, t_dlist *current);
int		ft_dlstrank_prev(t_dlist *dlst_from, t_dlist *current);

size_t	ft_dlstsize_total(t_dlist *dlst);
size_t	ft_dlstsize_start(t_dlist *dlst);
size_t	ft_dlstsize_end(t_dlist *dlst);

///////////////////
////  FT_CONV  ////
///////////////////

int		*ft_aarrtoiarr(t_cchar **strarr, size_t n);
char	**ft_iarrtoaarr(int *arr, size_t na);
int		*ft_aarrtoiarr_base(t_cchar **strarr, size_t n, t_cchar *base);
char	**ft_iarrtoaarr_base(int *arr, size_t na, t_cchar *base);

void	**ft_aarrtoparr_c(t_cchar **strarr, size_t n);
char	**ft_parrtoaarr_c(void **arr, size_t na);
char	**ft_parrtoaarr_m(void **arr, size_t na);

t_uns	*ft_aarrtouarr(t_cchar **strarr, size_t n);
t_uns	*ft_aarrtouarr_base(t_cchar **strarr, size_t n, t_cchar *base);
char	**ft_uarrtoaarr(t_uns *arr, size_t na);
char	**ft_uarrtoaarr_base(t_uns *arr, size_t na, t_cchar *base);

int		ft_atoi(t_cchar *str);
int		ft_atoi_base(t_cchar *str, t_cchar *base);
t_llint	ft_atoll(t_cchar *str);
t_llint	ft_atoll_base(t_cchar *str, t_cchar *base);

t_uns	ft_atou(t_cchar *str);
t_uns	ft_atou_base(t_cchar *str, t_cchar *base);
t_lluns	ft_atollu(t_cchar *str);
t_lluns	ft_atollu_base(t_cchar *str, t_cchar *base);

char	*ft_itoa(int n);
char	*ft_itoa_base(int n, t_cchar *base);
char	*ft_lltoa(t_llint n);
char	*ft_lltoa_base(t_llint n, t_cchar *base);

t_dlist	*ft_lsttodlst(t_list *lst, void (*del)(void *));
t_list	*ft_dlsttolst(t_dlist *dlst, void (*del)(void *));

t_list	*ft_parrtolst(void **arr, size_t n, void (*del)(void *));
t_dlist	*ft_parrtodlst(void **arr, size_t n, void (*del)(void *));
void	**ft_lsttoparr(t_list *lst);
void	**ft_dlsttoparr(t_dlist *dlst);

char	*ft_utoa(t_uns n);
char	*ft_utoa_base(t_uns n, t_cchar *base);
char	*ft_llutoa(t_lluns n);
char	*ft_llutoa_base(t_lluns n, t_cchar *base);

/////////////////
///  FT_EXT  ////
/////////////////

t_list	*ft_filetolst(int fd);
t_dlist	*ft_filetodlst(int fd);

char	*ft_gnl(int fd);
char	*ft_gnl_mf(int fd);
int		ft_gnla(int fd, char **addr);
int		ft_gnla_mf(int fd, char **addr);

char	*get_next_line(int fd);
char	*get_next_line_mf(int fd);

///////////////////
////  FT_MATH  ////
///////////////////

int		ft_base_valid(t_cchar *base);
int		ft_sizeinbase_int(int n, int base_size);
int		ft_sizeinbase_ll(t_llint n, int base_size);
int		ft_sizeinbase_uns(t_uns n, int base_size);
int		ft_sizeinbase_lluns(t_lluns n, int base_size);

int		ft_bestest_two(int a, int b, int (*f)(int, int));
int		ft_bestest_intarr(int *arr, size_t n, int (*f)(int, int));
size_t	ft_bestest_arr_ind(int *arr, size_t n, int (*f)(int, int));

void	*ft_bestestp_twop(void *a, void *b, int (*f)(void *, void *));
void	*ft_bestestp_parr(void **arr, size_t n, int (*f)(void *, void *));
size_t	ft_bestestp_parr_ind(void **arr, size_t n, int (*f)(void *, void*));

int		ft_greater_equal(int a, int b);
int		ft_greater_strict(int a, int b);
int		ft_greatest_two(int a, int b);
int		ft_greatest_set(int *arr, size_t n);
size_t	ft_greatest_intarr_ind(int *arr, size_t n);

t_list	*ft_worstestlst_two(t_list *a, t_list *b, int (*f)(void *, void *));
t_list	*ft_bestestlst_two(t_list *a, t_list *b, int (*f)(void *, void *));
t_dlist	*ft_worstestdlst_two(t_dlist *a, t_dlist *b, int (*f)(void *, void *));
t_dlist	*ft_bestestdlst_two(t_dlist *a, t_dlist *b, int (*f)(void *, void *));

int		ft_intnoverflow(t_cchar *str);

int		ft_power(int n, int p);
t_llint	ft_powerll(t_llint n, t_llint p);

int		ft_abs(int n);
t_llint	ft_absll(t_llint n);
int		ft_revsign(int *n);
int		ft_sign(int n);

int		ft_smaller_equal(int a, int b);
int		ft_smaller_strict(int a, int b);
int		ft_smallest_two(int a, int b);
int		ft_smallest_intarr(int *arr, size_t n);
size_t	ft_smallest_intarr_ind(int *arr, size_t n);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);

int		ft_tosign(int *n, int s);
t_llint	ft_tosignll(t_llint *n, int s);
t_uns	ft_touns(int n);
t_lluns	ft_tolluns(t_llint n);

int		ft_worstest_two(int a, int b, int (*f)(int, int));
int		ft_worstest_intarr(int *arr, size_t n, int (*f)(int, int));
size_t	ft_worstest_intarr_ind(int *arr, size_t n, int (*f)(int, int));

void	*ft_worstestp_parr(void **arr, size_t n, int (*f)(void *, void *));
void	*ft_worstestp_twop(void *a, void *b, int (*f)(void *, void *));
size_t	ft_worstestp_parr_ind(void **arr, size_t n, int (*f)(void *, void *));

/////////////////
///  FT_MEM  ////
/////////////////

void	*ft_calloc(size_t nmemb, size_t size);
void	**ft_freeparr(void **arr, size_t n);
char	**ft_freestrarr(char **arr, size_t n);

void	*ft_memcpy(void *dest, t_cvoid *src, size_t n);
void	*ft_memccpy(void *dest, t_cvoid *src, int c, size_t n);
void	*ft_memmove(void *dest, t_cvoid *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

void	ft_switchpoint(void **a, void **b);
void	ft_switchpointc(void *a, void *b, size_t n);
void	ft_switchchar(t_uchar *a, t_uchar *b);
void	ft_switchint(int *a, int *b);

void	*ft_memchr(t_cvoid *s, int c, size_t n);
void	*ft_memrchr(t_cvoid *s, int c, size_t n);
void	*ft_memmem(t_cvoid *h, size_t hl, t_cvoid *n, size_t nl);
int		ft_memcmp(t_cvoid *s1, t_cvoid *s2, size_t n);

//////////////////
////  FT_PUT  ////
//////////////////

////// Classic

void	ft_putchar(t_cchar c);
void	ft_putchar_fd(t_cchar c, int fd);
size_t	ft_putrschar_fd(t_cchar c, int fd);
size_t	ft_putrschar(t_cchar c);

void	ft_putendl(t_cchar *s);
void	ft_putendl_fd(t_cchar *s, int fd);
size_t	ft_putrsendl(t_cchar *s);
size_t	ft_putrsendl_fd(t_cchar *s, int fd);

size_t	ft_putrslluns_base(t_lluns n, t_cchar *base);
size_t	ft_putrslluns_base_fd(t_lluns n, t_cchar *b, int fd);

void	ft_putlluns_base(t_lluns n, t_cchar *base);
void	ft_putlluns_base_fd(t_lluns n, t_cchar *b, int fd);

void	ft_putlluns(t_lluns n);
void	ft_putlluns_fd(t_lluns n, int fd);
size_t	ft_putrsunsll(t_lluns n);
size_t	ft_putrsunsll_fd(t_lluns n, int fd);

void	ft_putnbr_base(int n, t_cchar *base);
void	ft_putnbr_base_fd(int n, t_cchar *base, int fd);
size_t	ft_putrsnbr_base(int n, t_cchar *base);
size_t	ft_putrsnbr_base_fd(int n, t_cchar *base, int fd);

void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_putrsnbr(int n);
size_t	ft_putrsnbr_fd(int n, int fd);

void	ft_putnbrll_base(t_llint n, t_cchar *base);
void	ft_putnbrll_base_fd(t_llint n, t_cchar *base, int fd);
size_t	ft_putrsnbrll_base(t_llint n, t_cchar *base);
size_t	ft_putrsnbrll_base_fd(t_llint n, t_cchar *base, int fd);

void	ft_putnbrll(t_llint n);
void	ft_putnbrll_fd(t_llint n, int fd);
size_t	ft_putrsnbrll(t_llint n);
size_t	ft_putrsnbrll_fd(t_llint n, int fd);

void	ft_putstr(t_cchar *s);
void	ft_putstr_fd(t_cchar *s, int fd);
size_t	ft_putrsstr(t_cchar *s);
size_t	ft_putrsstr_fd(t_cchar *s, int fd);

void	ft_putstrn(t_cchar *s, size_t n);
void	ft_putstrn_fd(t_cchar *s, size_t n, int fd);
size_t	ft_putrsstrn(t_cchar *s, size_t n);
size_t	ft_putrsstrn_fd(t_cchar *s, size_t n, int fd);

size_t	ft_putrsuns_base(t_uns n, t_cchar *base);
size_t	ft_putrsuns_base_fd(t_uns n, t_cchar *base, int fd);

void	ft_putuns_base(t_uns n, t_cchar *base);
void	ft_putuns_base_fd(t_uns n, t_cchar *base, int fd);

void	ft_putuns(t_uns n);
void	ft_putuns_fd(t_uns n, int fd);
size_t	ft_putrsuns(t_uns n);
size_t	ft_putrsuns_fd(t_uns n, int fd);

////// Complxdef

void	ft_putdlst_def(t_dlist *dlst, void (*f)(void*, t_cchar*));
void	ft_putdlst_fd_def(t_dlist *dlst, int fd, \
	void (*f)(void*, t_cchar*, int));
void	ft_putdlstr_def(t_dlist *dlst, void (*f)(void*, t_cchar*));
void	ft_putdlstr_fd_def(t_dlist *dlst, int fd, \
	void (*f)(void*, t_cchar*, int));

void	ft_putintarr_base_def(t_cint *arr, t_cchar *base, size_t n);
void	ft_putintarr_base_fd_def(t_cint *arr, t_cchar *base, size_t n, int fd);

void	ft_putintarr_def(t_cint *arr, size_t n);
void	ft_putintarr_fd_def(t_cint *arr, size_t n, int fd);

void	ft_putlst_def(t_list *lst, void (*f)(void*, t_cchar*));
void	ft_putlst_fd_def(t_list *lst, int fd, void (*f)(void*, t_cchar*, int));

void	ft_putstrarr_def(t_cchar **arr, size_t n);
void	ft_putstrarr_fd_def(t_cchar **arr, size_t n, int fd);

////// Pput

void	ft_pputchar(void *content, t_cchar *base);
void	ft_pputchar_fd(void *content, t_cchar *base, int fd);

void	ft_pputendl(void *content, t_cchar *base);
void	ft_pputendl_fd(void *content, t_cchar *base, int fd);

void	ft_pputlluns_base(void *content, t_cchar *base);
void	ft_pputlluns_base_fd(void *content, t_cchar *base, int fd);

void	ft_pputlluns(void *content, t_cchar *base);
void	ft_pputlluns_fd(void *content, t_cchar *base, int fd);

void	ft_pputnbr_base(void *content, t_cchar *base);
void	ft_pputnbr_base_fd(void *content, t_cchar *base, int fd);

void	ft_pputnbr(void *content, t_cchar *base);
void	ft_pputnbr_fd(void *content, t_cchar *base, int fd);

void	ft_pputnbrll_base(void *content, t_cchar *base);
void	ft_pputnbrll_base_fd(void *content, t_cchar *base, int fd);

void	ft_pputnbrll(void *content, t_cchar *base);
void	ft_pputnbrll_fd(void *content, t_cchar *base, int fd);

void	ft_pputstr(void *content, t_cchar *base);
void	ft_pputstr_fd(void *content, t_cchar *base, int fd);

void	ft_pputuns_base(void *content, t_cchar *base);
void	ft_pputuns_base_fd(void *content, t_cchar *base, int fd);

void	ft_pputuns(void *content, t_cchar *base);
void	ft_pputuns_fd(void *content, t_cchar *base, int fd);

////// Printf

int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);

//////////////////
////  FT_FTU  ////
//////////////////

char	*get_next_line(int fd);
char	*get_next_line_mf(int fd);
size_t	ftu_printf_proflagextra(const char *frg, size_t n, void *val);
size_t	ftu_dprintf_proflagextra(const char *frg, size_t n, void *val, int fd);

#endif