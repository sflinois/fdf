/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:22:10 by sflinois          #+#    #+#             */
/*   Updated: 2017/06/05 17:05:05 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE 32

# include <string.h>
# include <inttypes.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_matrix
{
	int				nb_line;
	int				nb_col;
	int				**m;
}					t_matrix;

typedef struct		s_mtx4
{
	int				m[4][4];
}					t_mtx4;

typedef struct		s_vec4
{
	int				v[4];
}					t_vec4;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isneg(int c);
char				*ft_itoa(int n);
char				*ft_litoa(long int n);
char				*ft_imttoa(intmax_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strnochr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_wstrlen(wchar_t *wstr);
size_t				ft_wcharlen(wchar_t wc);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
										size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone_cmp(t_list **lst, t_list **del);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_pow(int nb, int pow);
int					ft_base2dec(int nb, int base);
int					ft_base2base(int nb, int base1, int base2);
t_btree				*ft_btree_create_node(void *item);
void				ft_btree_apply_prefix(t_btree *root,
		void (*applyf)(void *));
void				ft_btree_apply_infix(t_btree *root,
		void (*applyf)(void *));
void				ft_btree_apply_suffix(t_btree *root,
		void (*applyf)(void *));
char				*ft_itoa_base(unsigned int n, unsigned int base, int maj);
char				*ft_litoa_base(unsigned long int n, unsigned int base,
						int maj);
char				*ft_imttoa_base(uintmax_t n, unsigned int base, int maj);
char				ft_digit_to_char(int d, int base, int maj);
void				ft_strrev(char *str);
char				*ft_retwchar(wchar_t wc);
char				*ft_retwstr(wchar_t *wstr);
char				*ft_retnwstr(wchar_t *wstr, size_t size);
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
t_matrix			*ft_mtxnew(int nb_rows, int nb_cols, int **tab);
t_matrix			*ft_mtxmult(t_matrix *a, t_matrix *b);
t_matrix			*ft_mtxmultint(int a, t_matrix *b);

#endif
