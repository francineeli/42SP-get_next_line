/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:02:22 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/05 13:18:03 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	printf("---------------------------\nBUFFER_SIZE\t=\t%llu\n---------------------------\n", (unsigned long long int)BUFFER_SIZE);
	printf("---------------------------\nINT_MAX\t\t=\t%d\nLONG_MAX\t=\t%ld\nLL_MAX\t\t=\t%lld\nULL_MAX\t\t=\t%llu\n---------------------------\n", INT_MAX, LONG_MAX, LLONG_MAX, ULLONG_MAX);
	if (argc != 2)
	{
		printf("Nenhum arquivo para ler.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Arquivo não legível.\n");
		return (0);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
