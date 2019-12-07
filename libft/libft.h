/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:29:33 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/20 12:34:40 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *str, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
char			*ft_strdup(const char *s1);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strncat(char *restrict s1,
								const char *restrict s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_putendl(char const *s);
void			*ft_memalloc(size_t size);
int				ft_atoi(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_strdel(char **as);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_strsplit(char const *s, char c);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *conten, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_memdel(void **ap);
int				ft_intlen(int n);
size_t			ft_elementcount(char *s, char c);
size_t			ft_strlenc(char *s, char c);
char			*ft_strrev(char *str);
int				ft_iswhitespace(char c);
char			*ft_itoa(int n);
char			*ft_strndup(const char *s, size_t i);
int				ft_isupper(int s);
int				ft_islower(int c);
int				ft_str_is_alpha(char *s);
int				ft_str_is_lowercase(char *s);
int				ft_str_is_printable(char *s);
char			*ft_str_to_upper(char *s);
int				ft_wordlen(char *s);
int				ft_isspace(int c);
int				ft_wordlen(char *s);
char			*ft_str_to_lower(char *s);
t_list			*ft_strsplit_lst(char const *s, char c);
void			ft_printlst(t_list *elem);
int				ft_atoi_base(const char *str, int str_base);
int				ft_pow(int a, int value);
void			ft_putnbrlong_fd(long long n, int fd);
void			ft_putnbrlong(long long n);
void			ft_printhex(int num);
size_t			ft_strspn(const char *s, const char *charset);
char			*ft_itoa_base(int value, int base, char h);
int				ft_intlen_base(int n, int base);
void			ft_putstrc(char *s, int size);
void			ft_putstrc_fd(char *s, int fd, int size);
long long		ft_lenlong_base(long long n, int base);
char			*ft_longtoa_base(long long i, int base, char h);
#endif
