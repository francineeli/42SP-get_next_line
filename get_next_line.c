/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/06 21:51:42 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_alloc_first_line(char *str);
char	*ft_alloc_next_line(char *str);
char	*ft_read_line(int fd, char *str);
char	*get_next_line(int fd);

char	*ft_alloc_first_line(char *str)
{
	char	*strcheck;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	strcheck = malloc(i + 2);
	if (!strcheck)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
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
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i <= 0)
		{
			free (buf);
			return (NULL);
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
	static char	*finalstr;
	char		*str_read;

	str_read = "\0";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	finalstr = ft_read_line(fd, finalstr);
	if (!finalstr)
		return (NULL);
	str_read = ft_alloc_first_line(finalstr);
	finalstr = ft_alloc_next_line(finalstr);
	if (!finalstr)
		return (NULL);
	return (str_read);
}
