/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/06 19:23:29 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_read_line(int fd, char *str);
char	*ft_check_first_line(char *str);
char	*ft_check_next_line(char *str);
char	*get_next_line(int fd);

char	*ft_check_first_line(char *str)
{
	char	*strcheck;
	size_t	i;
	
	i = 0;
	if(str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	strcheck = malloc(sizeof(char) * (i + str[i] == '\n' + 1));
	if (!strcheck)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		strcheck[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		strcheck[i++] = '\n';
	strcheck[i] = '\0';
	return (strcheck);
}

char	*ft_check_next_line(char *str)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0; 
	while (str[i] != '\0' && str[i] != '\n')
		i++;	
	newstr = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!newstr)
		return (NULL);
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		newstr[j] = str[i + j];
		j++;
	}			
	newstr[j] = '\0';			
	if (str)
		free (str);
	return (newstr);
}

char	*ft_read_line(int fd, char *str)
{
	char 	*buf;
	int		t; 
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		t = read (fd, buf, BUFFER_SIZE);
		printf("%d\n", t);
		if (t <= 0)
		{
			free (buf);
			return (str);
		}
		buf[t] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	if (t == -1)
	{
		free (str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char	*result;
	
	str = "\0";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = ft_read_line(fd, result);
	if (result != NULL && *result != '\0')
	str = ft_check_first_line(result);
	result = ft_check_next_line(result);
	if (!result)
		return (NULL);
	return (str);
}

