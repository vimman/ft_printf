/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 20:04:08 by qdurot            #+#    #+#             */
/*   Updated: 2017/08/12 20:04:15 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Search for the file descriptor in the list
** Create it if doesn't exist
** Add a new node if fd haven't been found in the list
*/

static t_list	*ft_node(t_list **list, int fd)
{
	t_list	*node;

	node = *list;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	if (!(node = ft_lstnew("", 1)))
		return (NULL);
	node->content_size = fd;
	ft_lstadd(list, node);
	return (node);
}

/*
** Read and join buf until it finds a '\n' or read returns 0
*/

char			*ft_read(char **buf, int fd, char *ptr)
{
	int		ret;
	char	rd[BUFF_SIZE + 1];
	char	*free_ptr;

	while ((ret = read(fd, rd, BUFF_SIZE)))
	{
		rd[ret] = '\0';
		free_ptr = *buf;
		if (!(*buf = ft_strjoin(*buf, rd)))
			return (NULL);
		free(free_ptr);
		if ((ptr = ft_strchr(*buf, '\n')))
			return (ptr);
	}
	return (0);
}

/*
** This function verify if conditions are ok, set the pointer to '\n'
** call ft_read or split the buffer if necessary
*/

int				get_next_line(const int fd, char **line)
{
	char			*ptr;
	static t_list	*list;
	t_list			*node;
	char			*free_ptr;

	if (!(node = ft_node(&list, fd)) || line == NULL ||
		read(fd, node->content, 0) < 0)
		return (-1);
	ptr = ft_strchr(node->content, '\n');
	if (!ptr)
		ptr = ft_read((char **)&node->content, fd, ptr);
	if (ptr)
	{
		*ptr = '\0';
		*line = ft_strdup((char *)node->content);
		free_ptr = node->content;
		node->content = ft_strdup(ptr + 1);
		free(free_ptr);
		return (1);
	}
	*line = ft_strdup(node->content);
	node->content = ft_strdup("\0");
	return ((**line) ? 1 : 0);
}
