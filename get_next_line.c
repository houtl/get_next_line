/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:35:33 by thou              #+#    #+#             */
/*   Updated: 2016/12/16 16:35:41 by thou             ###   ########.fr       */
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
	static t_list	*tmp;
	t_list			*file;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	file = rightfile(&tmp, fd);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(file->content = ft_strjoin(file->content, buff)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	*line = ft_strsubc(file->content, '\n');
	(ft_strlen(*line) < ft_strlen(file->content)) ?
		file->content += (ft_strlen(*line) + 1) : ft_strclr(file->content);
	return (1);
}
