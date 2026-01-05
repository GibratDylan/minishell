/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:48:36 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 14:00:53 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 20
# define SUCCESS 0
# define FAIL 1

typedef struct s_stack
{
	int					*stack;
	int					top;
	int					size;
	int					cap;

}						t_stack;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef unsigned char	t_bool;

int						ft_printf(const char *str, ...);
char					*ft_itoa_base(unsigned long long n, char *base,
							t_bool is_address);
char					*ft_strdup_null(const char *s);
t_bool					ft_isalpha(int str);
t_bool					ft_isdigit(int str);
t_bool					ft_isalnum(int c);
t_bool					ft_isascii(int c);
t_bool					ft_isprint(int c);
size_t					ft_strlen(const char *s);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlcpy(char *dst, const char *src, size_t siz);
size_t					ft_strlcat(char *dst, const char *src, size_t siz);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(const char *s, int start, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
int						ft_atoi(const char *nptr);
char					*ft_strdup(const char *s);
void					*ft_calloc(size_t nmemb, size_t size);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin_free(char *s1, char *s2, unsigned int len,
							char *str_free);
char					*ft_strjoin(char const *s1, char const *s2,
							unsigned int len);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strtrim_free(char *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
int						ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new_lst);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new_lst);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
char					*get_next_line(int fd, int free_line_fd);
void					*ft_malloc(size_t nmemb, size_t size);
void					ft_free_malloc(void *ptr);
void					ft_free_all_malloc(void);
double					ft_absf(double value);
int						ft_abs(int value);
t_bool					ft_min(int min, int max);
t_bool					ft_max(int min, int max);
void					ft_swap(int *nbr1, int *nbr2);
t_bool					ft_isspace(char c);
t_bool					ft_isnumber(const char *str);
t_bool					ft_isint(char *str);
void					ft_free_tab(void **tab);
t_list					*new_node(void *content);
void					free_node(t_list **malloc_list);
void					*ft_realloc(void *ptr, size_t size_before,
							size_t size_after);
double					ft_atof(const char *nptr);
int						prev_circular(t_stack *stack, int nbr, int cap);
int						next_circular(t_stack *stack, int nbr, int cap);
t_bool					init_circular(t_stack *stack, int size);
t_bool					issorted_sorted(t_stack *stack);
double					normalization(double min_to, double max_to,
							double max_from, short value);
int						ft_tab_len(char **tab);
char					**ft_cpy_tab(char **tab);

#endif
