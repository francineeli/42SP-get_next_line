/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/05 11:33:15 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_read_line(int fd, char *str);
char	*ft_check_first_line(char *str);
char	*ft_check_next_line(char *str);
char	*get_next_line(int fd);

char	*ft_strchr(char *str, int c)
{
	int	i;
	const char *result;

	i = 0;
	result = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == (char) c)
			{
				result = &str[i];
				return ((char *) str + i);
			}
			i++;
		}
		if (c == 0)
			result = (str + ft_strlen(str));
		return ((char *) result);
	}
	return (NULL);
}

char	*ft_check_first_line(char *str)
{
	char	*result;
	size_t	i;
	
	i = 0;
	if(str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	result = malloc (sizeof(char) * (i = str[i] == '\n' + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*ft_check_next_line(char *str)
{
	char	*new_result;
	size_t	i;
	size_t	j;

	i = 0; 
	while (str[i] != '\0' && str[i] != '\n')
		i++;	
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_result = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (new_result == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		new_result[j] = str[i + j];
		j++;
	}			
	new_result[j] = '\0';			
	free (str);
	return (new_result);
}

char	*ft_read_line(int fd, char *str)
{
	char 	*buf;
	ssize_t	ret; 
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	ret = 1;
	while (!ft_strchr(str, '\n'))
	{
		ret = read (fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free (buf);
			return (str);
		}	
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	if (ret == -1)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str = NULL;
	static char	*result;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str);
	if (result == NULL)
		return (NULL);
	result = ft_check_first_line(str);
	str = ft_check_next_line(str);
	return (result);
}

