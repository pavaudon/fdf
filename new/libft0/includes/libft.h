/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:15:56 by pavaudon          #+#    #+#             */
/*   Updated: 2018/01/10 21:10:21 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_toupper(char *str);
char				*ft_tolower(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t constent_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list *lst, t_list *new);
char				*ft_strndup(const char *s1, size_t n);
int					ft_nb_len(int n, int base);
char				*ft_itoa_base(int n, int base);
int					ft_ischar(int c, int compare);
char				*ft_lltoa_base(long long n, int base);
char				*ft_ulltoa_base(unsigned long long n, int base);
int					ft_ull_base_len(unsigned long long n, int base);
char				*ft_strfjoin(char const *s1, char const *s2, char to_free);
char				*ft_strfnjoin(const char *s1, const char *s2, int n,
					char to_free);
int					ft_ll_base_len(long long n, int base);
int					ft_ull_base_len(unsigned long long n, int base);
char				*ft_lltodst_base(long long n, char *dst, int base);
char				*ft_itodst_base(int n, char *dst, int base);
char				*ft_ftoa(double n);
int					ft_flen(double n);
char				*ft_ftodst(double n, char *str);
int					ft_get_min_max(int *tab, char *which);
int					*ft_tabffjoin(int *tab, int *to_add, int tablen,
					int to_addlen);
int					*ft_tabfsjoin(int *tab, int *to_add, int tablen,
					int to_addlen);
int					*ft_tabcpy(int *tab, int *to_cpy, int len);
int					*ft_tabndup(int *tab, int len, int n);
int					*ft_tabdup(int *tab, int len);
int					*ft_tabsub(int *tab, int start, int len);
int					get_next_line(const int fd, char **line);
void				ft_puttab(int *tab, int len);
int					ft_is_sort(int *tab, int len);
char				*ft_strfjoinset(char *str, char c, int len, int where);
char				*ft_strnjoinc(char c, int len);
int					ft_incharset(char c, char *charset);
int					ft_simple_printf(const char *format, ...);

#endif
