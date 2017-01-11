/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:35:33 by thou              #+#    #+#             */
/*   Updated: 2017/01/11 17:20:16 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*rightfile(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*tmp = NULL;
	t_list			*file;
	int				ret;
	char			*mem;

	SAFEMALLOC(!(fd < 0 || line == NULL || read(fd, buff, 0) < 0));
	file = rightfile(&tmp, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		mem = file->content;
		SAFEMALLOC((file->content = ft_strjoin(file->content, buff)));
		free(mem);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	SAFEMALLOC((*line = ft_strsubc(file->content, '\n')));
	mem = file->content;
	file->content = (ft_strlen(*line) < ft_strlen(file->content) ?
			ft_strdup(file->content + ft_strlen(*line) + 1) : ft_strnew('\0'));
	free(mem);
	return (1);
}
