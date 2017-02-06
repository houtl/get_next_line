/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:24:46 by thou              #+#    #+#             */
/*   Updated: 2017/02/06 15:29:38 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	int		fd1;
	char	*line;
	int		i;
	int		j;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("fd = %d:	%s\n", i, line);
		free(line);
		if ((j = get_next_line(fd1, &line)) == 1)
		{
			printf("fd1 = %d:    %s\n", j, line);
			free(line);
		}
	}
	while ((j = get_next_line(fd1, &line)) == 1)
	{
		printf("fd1 = %d:    %s\n", j, line);
		free(line);
	}
	printf("fd = %d:    %s\n", i, line);
	printf("fd1 = %d:    %s\n", j, line);
	free(line);
	return (0);
}
