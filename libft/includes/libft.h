/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:14:12 by rpapagna          #+#    #+#             */
/*   Updated: 2019/12/18 23:39:00 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

/*
**	----- ----- -----
**	MACROS
**	----- ----- -----
*/

# define MAX_FD 4096
# define PAGESIZE 4096

/*
**	----- ----- -----
**	STRUCTS
**	----- ----- -----
*/

/**
	* 2d int array struct
	*
	* @param        x x coodinate
	* @param        y y coodinate
**/
typedef struct s_point
{
	size_t			x;
	size_t			y;
}					t_point;

/**
	* Nodes used within the queue data structure
	*
	* @param		void* content - pointer to the content in the queue
	* @param		s_node* next - pointer to the next element in the queue
**/
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

/**
	* Queue data structure
	*
	* @param		t_node* fisrt - pointer to the first element in the queue
	* @param		t_node* last - pointer to the last element in the queue
**/
typedef struct s_queue
{
	t_node			*first;
	t_node			*last;
}					t_queue;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	----- ----- -----
**	Allocate
**	----- ----- -----
*/

char				*ft_itoa_base(int n, int base);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
char				*ft_strcnew(size_t len, char c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin3(char const *s1, char const *s2, \
								char const *s3);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strndup(const char *s, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strpop(char *str, size_t id);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_uitoa_base(unsigned int n, int base);

/*
**	----- ----- -----
**	Comparison
**	----- ----- -----
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *s, const char *to_find, size_t len);
char				*ft_strstr(const char *s, const char *to_find);

/*
**	----- ----- -----
**	Count
**	----- ----- -----
*/

int					ft_abs(int value);
double				abs_double(double value);
int					ft_atoi(const char *s);
unsigned long long	ft_atoull(const char *str);
int					ft_countwords(char const *s, char c);
unsigned long long	ft_hextoull(const char *str);
int					ft_intlen(int num);
double				ft_map_zero(double in, double max, \
								double start, double end);
int					ft_strchri(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strrchri(const char *s, int c);

/*
**	----- ----- -----
**	Is Type
**	----- ----- -----
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);

/*
**	----- ----- -----
**	List
**	----- ----- -----
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
**	----- ----- -----
**	Manipluate
**	----- ----- -----
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *dst, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_tolower_str(char *str);
int					ft_tolower(int c);
char				*ft_toupper_str(char *str);
int					ft_toupper(int c);
int					reverse_array(char **array, int n);

/*
**	----- ----- -----
**	Print
**	----- ----- -----
*/

int					ft_printf(char *str, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putnstr(const char *s, size_t len);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(const char *s);
int					ft_sprintf(char *buf, char *str, ...);
int					is_flag(char x);
char				*num_string_base(long long num, int base);
char				*num_string_u_base(unsigned long long num, int base);

int					get_next_line(const int fd, char **line);
int					ft_pipewrench(char *str, ...);

t_queue				*queue_init(void);
int					queue_is_empty(t_queue *queue);
void				*queue_peek(t_queue *queue);
void				enqueue(t_queue *queue, void *content);
void				*dequeue(t_queue *queue);

#endif
