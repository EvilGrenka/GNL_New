#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_fd
{
	int         fd;
	char        *reminder;
	struct s_fd *next;
}				t_fd;

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
bool 	search_nl(char *reminder);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_fd    *create_list_fd(int fd);

#endif