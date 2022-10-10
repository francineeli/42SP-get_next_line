/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:43:25 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/10 15:11:41 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" 

char	*ft_alloc_first_line(char *str);
char	*ft_alloc_next_line(char *str);
char	*ft_read_line(int fd, char *str);
char	*get_next_line(int fd);

char	*ft_alloc_first_line(char *str)
{
	char	*strcheck;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	strcheck = malloc(i + 1);
	if (!strcheck)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		strcheck[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		strcheck[i++] = '\n';
	strcheck[i] = '\0';
	return (strcheck);
}

char	*ft_alloc_next_line(char *str)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	newstr = malloc(ft_strlen(str) - i + 1);
	if (!newstr)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		newstr[j] = str[i + j];
		j++;
	}			
	newstr[j] = '\0';
	free (str);
	return (newstr);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		i;

	buf = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(str, '\n'))
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i <= 0)
		{
			free (buf);
			return (str);
		}
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*finalstr[1024];
	char		*str_read;

	str_read = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	finalstr[fd] = ft_read_line(fd, finalstr[fd]);
	if (!ft_strlen(finalstr[fd]))
	{
		free(finalstr[fd]);
		return (NULL);
	}
	else
	{
		str_read = ft_alloc_first_line(finalstr[fd]);
		finalstr[fd] = ft_alloc_next_line(finalstr[fd]);
	}
	// if (!finalstr)
	// 	return (NULL);
	return (str_read);
}
