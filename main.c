/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:24:46 by thou              #+#    #+#             */
/*   Updated: 2017/01/03 14:56:27 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	int		fd1;
	char	*line;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (get_next_line(fd1, &line) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
	}
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
