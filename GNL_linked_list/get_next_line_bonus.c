#include "get_next_line_bonus.h"

static t_fd *get_add_fd(int fd, t_fd **root)
{
    t_fd *new;
    t_fd *exist;

    exist = *root;
    while(exist)
    {
        if (exist->fd == fd )
            return exist;
        exist = exist -> next;
    }
    new = create_list_fd(fd);
    new -> next = *root;
    *root = new;
    return new;
}
 
static char	*ft_save_buffer(char *reminder, char *buffer)
{
	char	*leaks;

	if (reminder)
	{
		leaks = reminder;
		reminder = ft_strjoin(reminder, buffer);
		free(leaks);
	}
	else
		reminder = ft_strjoin(reminder, buffer);
	return (reminder);
}

static void del_fd(t_fd *removable, t_fd **root)
{
	t_fd *prev;

	if(!root)
		return ;
	if(*root == removable)
	{
		*root = (*root) ->next;
		free(removable);
	}
	else
	{
		prev = *root;
		while (prev->next != removable)
			prev = prev->next;
		prev->next = removable->next;
		free(removable);
	}
}

static char	*get_line_reminder(t_fd *curr, t_fd **root)
{
	char	*leaks;
	size_t	i;
    char    *line;

    if(!(curr->reminder))
	{
		del_fd(curr, root);
        return NULL;
	}
	i = 0;
	while (curr->reminder[i] != '\n' && curr->reminder[i])
		i++;	
	if (i < ft_strlen(curr->reminder))
	{
        leaks = curr->reminder;
		line = ft_substr(curr->reminder, 0, ++i);
		curr->reminder = ft_substr(curr->reminder, i, ft_strlen(curr->reminder));
		free(leaks);
	}
	else
	{
		line = curr->reminder;
		curr->reminder = NULL;
	}
	return (line);
}

char *get_next_line(int fd)
{
	char        *buffer;
	int         readed;
	static t_fd *root;
    t_fd        *curr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char*) malloc (sizeof(char) *(BUFFER_SIZE + 1));
	if(!buffer)
		return NULL;
    curr = get_add_fd(fd, &root);
    if(!curr)
		return NULL;
	readed = read(curr->fd, buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		buffer[readed] = '\0';
		curr->reminder = ft_save_buffer(curr->reminder, buffer);
		if (search_nl(curr->reminder))
			break ;
		readed = read(curr->fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return get_line_reminder(curr, &root);
}